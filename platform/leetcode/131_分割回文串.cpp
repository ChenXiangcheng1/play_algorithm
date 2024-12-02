#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    bool is_palindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    void backtracking(const string &s, int index,vector<string> &s_vec, vector<vector<string>> &res) {
        // 递归终止条件
        if (index == s.size()) {
            res.push_back(s_vec);
            return;
        }
        // 调用递归
        for (int r = index; r < s.size(); r++) {
            if (is_palindrome(s, index, r)) {
                s_vec.push_back(s.substr(index, r-index+1));
                backtracking(s, r+1, s_vec, res);
                s_vec.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> s_vec;

        if (s == "")
            return res;

        backtracking(s, 0, s_vec, res);
        return res;
    }
};

int main()
{
    vector<vector<string>> res = Solution().partition("efe");
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
