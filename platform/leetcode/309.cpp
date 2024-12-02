#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// N=5000 所需时间复杂度<=O(n^2)

class Solution {
// 定义无后效性的状态：只保存一个信息i是不可以的。
// 状态 动态规划：子问题是数据规模更小的问题(即前一天)，状态是所有能表示的信息(尽量不冗余)，
public:
    // 状态机
    int maxProfit_norm(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(3, INT_MIN));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = dp[i-1][1] + prices[i];
        }
        return max(dp[n-1][0], dp[n-1][2]);
    }

    // 采用滚动数组优化
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(2, vector<int>(3, INT_MIN));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < n; i++) {
            dp[i%2][0] = max(dp[(i-1)%2][0], dp[(i-1)%2][2]);
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][0] - prices[i]);
            dp[i%2][2] = dp[(i-1)%2][1] + prices[i];
        }
        return max(dp[(n-1)%2][0], dp[(n-1)%2][2]);
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(ivec) << endl;
    return 0;
}
