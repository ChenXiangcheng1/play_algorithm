#include <iostream>
#include <map>
#include <utility>
 
using namespace std;

typedef long long ll;

map<pair<ll, ll>, ll> mp;

int main()
{
    ll n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a < b) {
            pair<ll, ll> key = make_pair(a, b);
            if (mp.find(key) == mp.end()) {
                mp[key] = 1;
            } else {
                mp[key] ++;
            }
        } else if (a > b) {
            pair<ll, ll> key = make_pair(b, a);
            if (mp.find(key) == mp.end()) {
                mp[key] = -1;
            } else {
                mp[key] --;
            }
        // } else {
        //     pair<ll, ll> key = make_pair(a, b);
        //     if (mp.find(key) == mp.end()) {
        //         mp[key] = 1;
        //     } else {
        //         mp[key] = 1ll - mp[key];
        //     }
        }
    }
    for (map<pair<ll, ll>, ll>::iterator it = mp.begin(); it != mp.end(); it++) {
        if ((*it).second != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}