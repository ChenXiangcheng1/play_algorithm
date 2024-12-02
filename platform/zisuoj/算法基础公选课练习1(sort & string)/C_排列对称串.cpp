#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cmp(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    string str, ans[105];
    int k = 0;
    while(getline(cin, str)) {
        string t = str;
        reverse(t.begin(), t.end());
        if (str.compare(t) == 0) {
            ans[k++] = str;
        }
    }
    sort(ans, ans+k, cmp);
    for (int i = 0; i < k; i++)
        cout << ans[i] << endl;
    return 0;
}
