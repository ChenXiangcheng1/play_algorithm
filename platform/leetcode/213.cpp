#include <iostream>
#include <vector>

using namespace std;

// N=100 所需时间复杂度<=O(n^4)
// 这道题问题在与是一个环，如何定义出无后效性的状态：经过我的思考，每一位的元素都是不可替代的。

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n);
        if (n == 0)
            return 0;
        dp[0] = 0;  // 表示[0,i]的价值
        // 循环也不知道如何开始，第一个开始的地方不确定。解决方式：两次dp选最大的
        for (int i = 1; i <= n - 1; i++) {
            dp[i] = max(dp[i-1] ,(i-2>=0 ? nums[i]+dp[i-2] : nums[i]));
        }
        res = dp[n-1];
        dp.clear();
        dp[0] = nums[0];
        for (int i = 1; i <= n - 2; i++) {
            dp[i] = max(dp[i-1] ,(i-2>=0 ? nums[i]+dp[i-2] : nums[i]));
        }
        res = max(res, n-2>=0 ? dp[n-2] : dp[0]);
        return res;
    }
};

int main()
{
    vector<int> ivec = {2, 3, 2};
    cout<<Solution().rob(ivec)<<endl;
    ivec = {1, 2, 3, 1};
    cout<<Solution().rob(ivec)<<endl;
    ivec = {1, 2, 3};
    cout<<Solution().rob(ivec)<<endl;
    ivec = {0};
    cout<<Solution().rob(ivec)<<endl;
    return 0;
}
