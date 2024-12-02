#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class Solution {
private:
    map<int, string> mp;
    vector<string> record;

    void init() {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
    }

    // digits的第k个字符
    void backtracking(string digits, int k, string str) {
        // 递归终止条件
        if (k >= digits.size()) {
            record.push_back(str);
            return;
        }

        // 调用递归
        assert(digits[k] >= '2' && digits[k] <= '9');
        string mp_str = mp[digits[k]-'0'];
        for (size_t i = 0; i < mp_str.size(); i++) {
            // str += mp_str[i];
            // backtracking(digits, k+1, str);
            // str.pop_back();  // 回溯
            backtracking(digits, k+1, str+mp_str[i]);
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        init();
        backtracking(digits, 0, "");
        return record;
    }
};

int main()
{
    vector<string> str_vec = Solution().letterCombinations("23");
    for (size_t i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().letterCombinations("");
    for (size_t i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().letterCombinations("2");
    for (size_t i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().letterCombinations("234");
    for (size_t i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }
    return 0;
}