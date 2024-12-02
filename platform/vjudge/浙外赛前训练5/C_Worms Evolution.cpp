#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, t, flag = 0;
    map<int, int> mp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        mp[t] = i;
    }
    for (map<int, int>::iterator it1 = mp.begin(); it1 != mp.end(); it1++) {
        for (map<int, int>::iterator it2 = mp.begin(); it2 != mp.end(); it2++) {
            if (it1 == it2) continue;
            if (mp.find(it1->first + it2->first) != mp.end()) {
                cout << mp.find(it1->first + it2->first)->second << " " << it1->second << " " << it2->second << endl;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag)
        cout << -1 << endl;
    return 0;
}
