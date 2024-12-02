#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, dest[1050], ind = 1;
    stack<int> stk;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dest[i];
    }
    // 从遍历入栈的列车编号的思路出发
    for (int i = 1; i <= n; i++) {
        // 若入栈的值等于出栈的值，则看下一个要出栈的值，并且要循环出栈
        if (i == dest[ind]) {
            ind++;
            while (!stk.empty()) {
                // 若栈顶等于要出栈的值，则出栈
                if (stk.top() == dest[ind]) {
                    stk.pop();
                    ind++;
                // 若不等于，则看下一个入栈的值
                } else {
                    break;
                }
            }
        // 若入栈的值小于出栈的值，则入栈
        } else if (i < dest[ind]) {
            stk.push(i);
        // 若入栈的值大于出栈的值，则返回false
        } else if (i > dest[ind]) {
            cout << "NO" << endl;
            return 0;
        }     
    }
    if (ind == n+1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
