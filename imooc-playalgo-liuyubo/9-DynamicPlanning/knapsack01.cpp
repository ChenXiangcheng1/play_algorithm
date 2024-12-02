#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

class Knapsack01 {
private:
    vector<vector<int>> memo;

    // 用[0...index]的物品，填充容积为c的背包的最大价值
    int bestValue(const vector<int> &w, const vector<int> v, int index, int c) {
        // 递归终止条件
        if (index < 0 || c <= 0)  // 没有物品的重量为0
            return 0;
        if (memo[index][c] != -1)
            return memo[index][c];

        // 调用递归
        int res = bestValue(w, v, index-1, c);

        if (c >= w[index])
            res = max(res, v[index] + bestValue(w, v, index-1, c-w[index]));

        memo[index][c] = res;
        return res;
    }

public:
    // 记忆化搜索
    int knapsack01_memo(const vector<int> &w, const vector<int> &v, int C) {
        int n = w.size();
        memo = vector<vector<int>>(n, vector<int>(C+1, -1));
        return bestValue(w, v, n-1, C);
    }

    // 初始化为v[i]的版本
    int knapsack01_dp2(const vector<int> &w, const vector<int> &v, int C) {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0)
            return 0;
        vector<vector<int>> memo(n, vector<int>(C+1, -1));
        for (int i = 0; i <= C; i++) {
            memo[0][i] = i >= w[0] ? v[0] : 0;
        }
        for (int i = 1; i < n; i++) {  // 第i物品
            for (int j = 0; j <= C; j++) {
                memo[i][j] = memo[i-1][j];
                if (j >= w[i])  // 事件-状态机
                    memo[i][j] = max(memo[i][j], v[i] + memo[i-1][j-w[i]]);  // 动作-状态机  // 可以用滚动数组优化空间
            }
        }
        return memo[n-1][C];
    }

    // 初始化为0的版本
    int knapsack01_dp(const vector<int> &w, const vector<int> &v, int C) {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0)
            return 0;
        vector<vector<int>> memo(n+1, vector<int>(C+1, 0));
        for (int i = 1; i <= n; i++) {  // 第i状态
            for (int j = 1; j <= C; j++) {
                memo[i][j] = memo[i-1][j];
                if (j >= w[i-1])  // 事件-状态机
                    memo[i][j] = max(memo[i-1][j], v[i-1] + memo[i-1][j-w[i-1]]);  // 动作-状态机  // 可以用滚动数组优化空间
            }
        }
        return memo[n][C];
    }

    // 原地状态转移+初始化为v[i]的版本
    int knapsack01_dp_pro(const vector<int> &w, const vector<int> &v, int C) {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0)
            return 0;
        vector<int> memo(C+1, -1);
        for (int i = 0; i <= C; i++) {
            memo[i] = i >= w[0] ? v[0] : 0;
        }
        for (int i = 1; i < n; i++) {  // 第i物品
            for (int j = C; j >= w[i]; j--) {  // 从大容量到小容量判断，当容量放不下时不放，优化时间(没有重量为0的物品)
                memo[j] = max(memo[j], v[i] + memo[j-w[i]]);  // 原地状态转移，优化空间为O(C)
            }
        }
        return memo[C];
    }

    // 原地DP+初始化为0的版本
    int knapsack01_dp_pro2(const vector<int> &w, const vector<int> &v, int C) {
        assert(w.size() == v.size());
        int n = w.size();
        if (n == 0)
            return 0;

        vector<int> memo(C+1, 0);
        for (int i = 1; i <= n; i++) {  // 第i状态
            for (int j = C; j >= w[i-1]; j--) {  // 从大容量到小容量判断，当容量放不下时不放，优化时间(没有重量为0的物品)
                memo[j] = max(memo[j], v[i-1] + memo[j-w[i-1]]);  // 原地状态转移，优化空间为O(C)
            }
        }
        return memo[C];
    }
};

int main()
{
    vector<int> w = {1, 2, 3};
    vector<int> v = {6, 10, 12};
    cout<<Knapsack01().knapsack01_memo(w, v, 5)<<endl;
    cout<<Knapsack01().knapsack01_dp_pro2(w, v, 5)<<endl;
    return 0;
}
