#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isAlphaOrNum(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');  // 字符判断数字，一定是和字符比较''
    }

public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (isAlphaOrNum(s[l]) && isAlphaOrNum(s[r])) {
                char t1 = s[l] >= 'A' && s[l] <= 'Z' ? s[l]+32 : s[l];  // 不要吝啬临时变量
                char t2 = s[r] >= 'A' && s[r] <= 'Z' ? s[r]+32 : s[r];
                if (t1 != t2)
                    return false;
                l++;
                r--;
            }
            if (!isAlphaOrNum(s[l]))
                l++;
            else if (!isAlphaOrNum(s[r]))
                r--;
        }
        return true;
    }
};

int main()
{
    cout << Solution().isPalindrome("0A man, a plan, a canal: PanamaP") << endl;
    return 0;
}

