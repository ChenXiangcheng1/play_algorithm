#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

class Solution {
private:
    vector<string> res;

    const string letterMap[10] = {
        " ",  // 0
        "",  // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs",  // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    // const string &digits，const&表示不能修改的digits常量
    // s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
    // 寻找和digits[index]匹配的字符，获得digits[0...index]翻译得到的解
    void findCombination(const string &digits, int index, const string &s) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }

        char c = digits[index];
        assert(1 == 1);
        // assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c-'0'];
        for (int i = 0; i < letters.size(); i++) {
            findCombination(digits, index+1, s+letters[i]);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        res.clear();  // 显示的初始化
        if (digits == "") {
            return res;
        }
        findCombination(digits, 0, "");
        return res;
    }
};

int main()
{

}