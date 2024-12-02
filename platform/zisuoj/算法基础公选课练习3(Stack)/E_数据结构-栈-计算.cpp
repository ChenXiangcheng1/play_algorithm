#include <iostream>
#include <cmath>
#include <cctype>
#include <stack>

using namespace std;

/*
	场调度算法
	中缀表达式转后缀表达式(逆波兰表达式)

	另外，此题没有负数
*/

string str;
stack<int> suffix_nums;  // 将后缀表达式用两个栈分别存储数字和操作符
stack<char> suffix_opts;  // 维护一个优先级单调栈，栈顶优先级高，栈底优先级低。

int opt_level(char ch) {
	if (ch == '(') {  // 左括号的优先级最低，因为其他符号计算到低优先级符号左括号就要停止计算 等待右括号
		return 0;		// 也可以不给(设置优先级，而是选择在while中判断栈顶!=(，即也是到(结束
	} else if (ch == '+' || ch == '-') {
		return 1;
	} else if (ch == '*' || ch == '/') {
		return 2;
	} else if (ch == '^') {
		return 3;
	}
	cout << "No define the opt level" << endl;
	return -1;
}

void calc() {
	int y = suffix_nums.top();
	suffix_nums.pop();
	int x = suffix_nums.top();
	suffix_nums.pop();
	char ch = suffix_opts.top();
	suffix_opts.pop();
	switch (ch)
	{
		case '+':
			suffix_nums.push(x + y);
			break;
		case '-':
			suffix_nums.push(x - y);
			break;
		case '*':
			suffix_nums.push(x * y);
			break;
		case '/':
			suffix_nums.push(x / y);
			break;
		case '^':
			suffix_nums.push((int)pow(x, y));
			break;
		default:
			cout << "No define the oprator." << endl;
			break;
	}
}

int main()
{
	cin >> str;
	int t = 0, flag = 0;  // 用于计算数字
	for (size_t i = 0; i < str.size(); i++) {
		// 若当前读到的str[i]是数字
		if (isdigit(str[i])) {
			t = t * 10 + str[i] - '0';
			flag = 1;
		// 2 若当前读到的str[i]是字符
		} else {
			// 1 若上一个读到的数字，则将数字压栈后将数字和数字标记置0
			if (flag) {  // flag == 1，表示之前读取的str[i-1]是数字
				suffix_nums.push(t);
				flag = t = 0;
			}
			// 若当前读到的是左右括号，需要特判(因为其前后可能为符号)在其他符号判断之前
			// 若*当前符号是左括号*则将当前符号直接压栈
			if (str[i] == '(') {
				suffix_opts.push('(');
				continue;  // 读取下一个字符
			// 2.1.1 若*当前符号是右括号*则栈顶元素依次出栈（到左括号为止，左括号要出栈）,并入队
			} else if (str[i] == ')') {
				while (suffix_opts.top() != '(') {
					calc();
				}
				suffix_opts.pop();
				continue;
			}
			// 若当前读到的是+-*/^
			// 2.1.2 若*当前符号优先级低于栈顶元素优先级*则计算栈中优先级高的操作再压数字栈，再将当前读到的符号压符号栈
			while (!suffix_opts.empty() && opt_level(suffix_opts.top()) >= opt_level(str[i])) {
				calc();
			}
			// 2.2.2 若*当前符号优先级高于栈顶符号*或者*栈空*或者*栈顶为左括号*则将当前符号直接压栈
			suffix_opts.push(str[i]);
		}
	}
	if (flag) {
		suffix_nums.push(t);
	}
	while (!suffix_opts.empty()) {
		calc();
	}
	cout << suffix_nums.top() << endl;
	return 0;
}
