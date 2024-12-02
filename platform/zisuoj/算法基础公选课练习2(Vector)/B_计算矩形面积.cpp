#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ll x1, x2, y1, y2;
    vector<ll> ivec;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        ivec.push_back(abs(x2 - x1) * abs(y2 - y1));
    }
    sort(ivec.begin(), ivec.end());
    for (size_t i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << endl;
    }
    return 0;
}
