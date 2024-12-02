#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int t;
    pair<string, int> kv;
    vector<pair<string, int>> pair_vec;
    cin >> t;
    while (t--) {
        cin >> kv.first >> kv.second;
        pair_vec.push_back(kv);
    }
    sort(pair_vec.begin(), pair_vec.end(), cmp);
    for (size_t i = 0; i < pair_vec.size(); i++) {
        cout << pair_vec[i].first << " " << pair_vec[i].second << endl;
    }
    return 0;
}
