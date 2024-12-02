#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// N=100 所需时间复杂度<=O(n^4)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  // 需要判断size为0的情况
            return 0;
        vector<int> dp(n+1);  // 状态：[i,len)的价值
        // dp[n] = 0;
        dp[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            // dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
            dp[i] = max(dp[i+1], nums[i] + (i+2 < n ? dp[i+2] : 0));
        }
        return dp[0];
    }

    int rob2(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 )
            return 0;

        // the max profit for robbing nums[0...i]
        vector<int> memo(n, 0);
        memo[0] = nums[0];  // 状态：[0,i]的价值
        for(int i = 1 ; i < n ; i ++)
            memo[i] = max(memo[i - 1],
                          nums[i] + (i - 2 >= 0 ? memo[i - 2] : 0));

        return memo[n-1];
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 1};
    cout<<Solution().rob(vec)<<endl;
    vec = {2, 7, 9, 3, 1};
    cout<<Solution().rob(vec)<<endl;
    return 0;
}
