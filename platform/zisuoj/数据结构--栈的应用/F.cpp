#include <iostream>
#include <cctype>
#include <stack>

using namespace std;

string str;
stack<int> suffix_num;
stack<char> suffix_opts;

int opt_level(char ch) {
    if (ch == '(') {
        return 0;
    }else if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        cout << "No define the oprator's level." << endl;
        return -1;
    }
}

void calc() {
    int y = suffix_num.top();
    suffix_num.pop();
    int x = suffix_num.top();
    suffix_num.pop();
    char ch = suffix_opts.top();
    suffix_opts.pop();
    switch (ch)
    {
    case '*':
        suffix_num.push(x * y);
        break;
    case '/':
        suffix_num.push(x / y);
        break;
    case '+':
        suffix_num.push(x + y);
        break;
    case '-':
        suffix_num.push(x - y);
        break;
    default:
        cout << "No define the oprator calc." << endl;
    }
}

bool is_op(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 不合法的情况：连续的运算符，合法返回true
bool check1() {
    for (size_t i = 1; i < str.size() - 1; i++) {
        if (is_op(str[i]) && is_op(str[i-1])) {
            return false;
        }
    }
    return true;
}

// 不合法的情况：括号不匹配，不合法返回true
bool check2() {
    stack<char> stk;
    for (size_t i = 0; i < str.size() - 1; i++) {
        if (str[i] != '(' || str[i] != ')') continue;
        else if (str[i] == '(') stk.push(')');
        else if (!stk.empty()) stk.pop();
        else return false;
    }
    return stk.empty();
}

int main()
{
    cin >> str;  // getline(cin, str, '@');
    int t = 0, flag = 0;
    if (!check1() && check2()) {
        cout << "NO" << endl;
        return 0;
    }
    for (size_t i = 0; i < str.size() - 1; i++) {
        if (isdigit(str[i])) {
            t = 10 * t + str[i] - '0';
            flag = 1;
        } else {
            if (flag) {
                suffix_num.push(t);
                t = flag = 0;
            }
            if (str[i] == '(') {
                suffix_opts.push(str[i]);
                continue;
            } else if (str[i] == ')') {
                while (suffix_opts.top() != '(') {
                    calc();
                }
                suffix_opts.pop();
                continue;
            }
            // 这里也是单调栈，优先级单调增(栈底到栈顶)
            while (!suffix_opts.empty() && opt_level(suffix_opts.top()) >= opt_level(str[i])) {  // 注意这里是>=，同优先级前面的先计算，比如连续的除/
                calc();
            }
            // 符号压栈之前 对-负数特判
            if (str[i] == '-' && (i == 0 || str[i - 1] == '(')) {  // 负数的情况
                size_t j = i + 1;
                int t = 0;
                while (j < str.size() - 1 && isdigit(str[j])) {
                    t = 10 * t + str[j++] - '0';
                }
                suffix_num.push(-t);
                i = j - 1;  // 不要忘记修改索引i，指向负数的下一位
            } else {
                suffix_opts.push(str[i]);
            }
        }
    }
    if (flag) {
        suffix_num.push(t);
    }

    // while (!suffix_num.empty()) {
    //     cout << suffix_num.top() << endl;
    //     suffix_num.pop();
    // }
    // while (!suffix_opts.empty()) {
    //     cout << suffix_opts.top() << endl;
    //     suffix_opts.pop();
    // }

    while (!suffix_opts.empty()) {
        calc();
    }
    cout << suffix_num.top() << endl;
    return 0;
}
