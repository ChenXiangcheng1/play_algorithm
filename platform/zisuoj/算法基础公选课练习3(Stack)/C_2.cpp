#include <iostream>
#include <stack>

using namespace  std;

int main()
{
    char ch, sp;
    stack<int> stk;
    while ((ch = getchar()) != -1) {
        if (ch == '(') {
            stk.push(')');
        } else if (ch == '[') {
            stk.push(']');
        } else if (ch == ')' || ch == ']') {
            if (!stk.empty()) {
                sp = stk.top();
                stk.pop();
                if (sp != ch) {
                    cout << "Wrong" << endl;
                    return 0;
                }
            } else {
                cout << "Wrong" << endl;
                return 0;
            }            
        }
    }
    if (stk.empty()) {
        cout << "OK" << endl;
    } else {
        cout << "Wrong" << endl;
    }
    return 0;   
}
