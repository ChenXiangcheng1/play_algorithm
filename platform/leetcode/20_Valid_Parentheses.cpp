#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 遍历一遍 用栈作辅助空间
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } else {
                if (stack.size() == 0)
                    return false;
                char c = stack.top();
                stack.pop();
                char match;
                if (s[i] == ')')
                    match = '(';
                else if (s[i] == ']')
                    match = '[';
                else {  // s[i] == '}'
                    assert(s[i] == '}');
                    match = '{';
                }
                if (match != c)
                    return false;
            }
        }
        if (stack.size() == 0)
            return true;
        else
            return false;
    }
};
