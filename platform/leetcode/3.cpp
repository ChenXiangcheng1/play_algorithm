#include <bits/stdc++.h>

using namespace std;

// 在滑动窗口中做记录

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};  // ASCII字符0-255
        int l = 0, r = -1;  // 滑动窗口为 s[l:r]
        int res = 0;
        while (l < s.size()) {
            // 满足条件的窗口状态 滑动到 下个满足条件的窗口状态
            if (r+1 < s.size() && freq[s[r+1]] == 0) {
                freq[s[++r]]++;
            } else {
                freq[s[l++]]--;
            }
            // 计算结果
            res = max(res, r-l+1);
        }
        return res;
    }
};
