#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;

    bool check(string s_sub) {
        // <"0" false
        for (int i = 0; i < s_sub.size(); i++) {
            if (s_sub[i] < '0' || s_sub[i] > '9')
                return false;
        }

        // 前导"0" false
        if (s_sub.size() > 1 && s_sub[0] == '0') {
            return false;
        }

        // >"255" false
        if (s_sub.size() == 3 && s_sub > "255") {
            return false;
        }

        return true;
    }

    // 解空间树为四层
    // 给定一个字符串把它分成四份，存到ip_ivector中，切割问题
    // s是递归常量，s_ind递归常量信息，bt_len是递归深度，str用于保存递归叶子节点
    void backtracking(const string &s, int s_ind, int bt_len, string str) {
        if (bt_len == 4) {
            if (s_ind == s.size()) {
                str.pop_back();
                res.push_back(str);
            }
            return;
        }

        for (int sub_len = 1; sub_len <= 3; sub_len++) {
            if (s_ind+sub_len > s.size())
                continue;
            string s_sub = s.substr(s_ind, sub_len);
            if (check(s_sub)) {
                backtracking(s, s_ind+sub_len, bt_len+1, str+s_sub+".");
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0, "");
        return res;
    }
};

int main()
{
    vector<string> str_vec = Solution().restoreIpAddresses("25525511135");
    for (int i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().restoreIpAddresses("0000");
    for (int i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().restoreIpAddresses("1111");
    for (int i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().restoreIpAddresses("010010");
    for (int i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }

    str_vec = Solution().restoreIpAddresses("101023");
    for (int i = 0; i < str_vec.size(); i++) {
        cout << str_vec[i] << endl;
    }
    return 0;
}
