#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main ()
{
    string str;
    string::size_type ind;  // 在16位int型的机器上，int类型变量最大只能表示32767个字符的string对象。而能容纳一个文件内容的string对象轻易就能超过这个数字，因此，为了避免溢出，保存一个string对象的size的最安全的方法就是使用标准库类型string::size_type().
    cin >> str;
    while ((ind = str.find("()")) != str.npos || (ind = str.find("[]")) != str.npos) {  // find()返回下标值，str.npos大于所有下标值
        str = str.replace(ind, 2, "");
    }
    if (str == "") {
        cout << "OK" << endl;
    } else {
        cout << "Wrong" << endl;
    }
    return 0;
}
