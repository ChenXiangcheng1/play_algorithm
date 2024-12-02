#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(string a, string b) {
    int cnt_a = 0, cnt_b = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == '1')
            cnt_a++;
    }
    for (size_t i = 0; i < b.size(); i++) {
        if (b[i] == '1')
            cnt_b++;
    }
    if (cnt_a == cnt_b)
        return a < b;
    return cnt_a < cnt_b;
}

int main()
{
    string strs[105];
    int k = 0;
    while (getline(cin, strs[k++]));
    k--;  // 因为最后一轮k会读到EOF再退出循环，所以还需要--
    sort(strs, strs+k, cmp);
    for (int i = 0; i < k; i++) {
        cout << strs[i] << endl;
    }
    return 0;
}
