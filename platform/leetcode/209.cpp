#include <bits/stdc++.h>

using namespace std;

// 设计子串
// 暴力：O(n^3)
// 对齐、维护一个窗口(前吞后消 达到 遍历子串的目的)：O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = -1, sum = 0, res = nums.size()+1;  // sum = nums[l: r]和
        while (l < nums.size()) {  // 当右边界到尾时结束
            // 窗口滑动逻辑: 如果小于target向右扩展，如果大于等于target向左扩展
            if (r+1 < nums.size() && sum < target) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }
            // 如果新窗口满足条件，则计算为res
            if (sum >= target) {
                res = min(res, r - l + 1);
            }
        }
        if (res == nums.size() + 1)
            return 0;
        return res;
    }
};