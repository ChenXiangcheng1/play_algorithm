#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// N=200 所需时间复杂度<=O(n^3)

// 状态转移方程:F(i,c) = F(i-1,c) || F(i-1,c-w(i))
// 两个状态可以转移到一个状态
// dp的时间复杂度O(2*10^6)

class Solution {
private:
    // memo[i][c] 表示使用索引为[0...i]元素，能否完全填充容量c的背包  (-1 表示未计算，0 表示不可以，1 表示可以.状态转移往往要多一个状态表示未计算，而动态规划要初始化)
    vector<vector<int>> memo;

    // [i,len)，判断i是否加入集合
    bool backtracking(vector<int> nums, int index, int sum) {
        if (index < 0 || sum < 0)
            return false;
        if (sum == 0)
            return true;
        if (memo[index][sum] != -1) {
            return memo[index][sum];
        }
        memo[index][sum] = backtracking(nums, index-1, sum) || backtracking(nums, index-1, sum-nums[index]);
        return memo[index][sum];
    }

public:
    // 记忆化搜索 超时
    bool canPartition_memo(vector<int>& nums) {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            assert(nums[i] > 0);
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1, -1));
        return backtracking(nums, nums.size()-1, sum/2);
    }

    // 动态规划 01背包
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            assert(nums[i] > 0);
            sum += nums[i];
        }
        if (sum%2 == 1)
            return false;
        int n = nums.size();
        int C = sum/2;
        vector<bool> dp(C+1, false);
        // for (int i = 0; i <= C; i++) {
        //     dp[i] = (nums[0] == i);
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = C; j >= nums[i]; j--) {
        //         dp[j] = dp[j] || dp[j-nums[i]];
        //     }
        // }
        for (int i = 1; i <= n; i++) {
            for (int j = C; j >= nums[i-1]; j--) {
                if (j == nums[i-1])
                    dp[j] = true;
                else
                    dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[C];
    }
};

int main()
{
    vector<int> ivec = {1, 1, 1, 1};
    cout << Solution().canPartition(ivec) << endl;
    return 0;
}
