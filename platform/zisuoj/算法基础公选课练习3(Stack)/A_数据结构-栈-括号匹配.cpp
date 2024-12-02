#include <iostream>
#include <stack>

using namespace std;

/*
如果是全括号 {[]} 的有效括号问题，操作字符串replace会快点

即没有其他字符，只有括号。那么解决方案可以是：用replace函数替换[]，循环一半字符总数的次数，若字符串为空则全匹配，反之亦然。
*/

int main()
{
    int ch;
    stack<int> stk;
    while ((ch = getchar()) != '@') {
        if (ch == '(') {
            stk.push(ch);
        } else if (ch == ')') {
            stk.pop();
        }
    }
    if (stk.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
