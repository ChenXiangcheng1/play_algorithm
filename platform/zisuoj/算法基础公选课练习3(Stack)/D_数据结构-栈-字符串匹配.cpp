#include <iostream>
#include <stack>
#include <map>

using namespace std;

// 从内到外必须是<>1,()2,[]3,{}4
// <()>: false

string str;
map<char, int> bracket_map;  // 可以用{}初始化

// 多个测试用例的题目，给每个用例写个方法更方便，使用方法方便输出返回结束
void str_match() {
    stack<char> stk;
    char sp;
    for (string::iterator it = str.begin(); it < str.end(); it++) {
        // 括号需要有顺序，只需要在不符合顺序时return就好了
        if ((*it == '<' || *it == '{' || *it == '[' || *it == '(') && !stk.empty() && bracket_map[stk.top()] < bracket_map[*it]) {
            cout << "NO" << endl;
            return;
        }
        if (*it == '(') {
            stk.push(')');
        } else if (*it == '[') {
            stk.push(']');
        } else if (*it == '<') {
            stk.push('>');
        } else if (*it == '{') {
            stk.push('}');
        } else {
            if (!stk.empty()) {
                sp = stk.top();
                stk.pop();
                if (sp != *it) {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (!stk.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    // 如果知道所有的key，那么可以用函数代替
    bracket_map['<'] = 1;
    bracket_map['('] = 2;
    bracket_map['['] = 3;
    bracket_map['{'] = 4;
    bracket_map['>'] = 1;
    bracket_map[')'] = 2;
    bracket_map[']'] = 3;
    bracket_map['}'] = 4;
    getchar();  // 之前还总结过！！这就不会用了？，记得getchar、getline之前要读走\n
    while (t--) {
        getline(cin, str);
        str_match();
    }
    return 0;
}
