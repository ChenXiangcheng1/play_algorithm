#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
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
    int t = 6;
    string str1, str2, str3;
    unordered_map<string, int> mp = {{"SiGuJian", 0}, {"KuHe", 0}, {"QingDi", 0}, {"YeLiuYun", 0}};
    while (t--) {
        getline(cin, str1, ' ');
        getline(cin, str2, ' ');
        getline(cin, str3);
        switch(str3[0]) {
            case 'S':
                mp[str1] += 3;
                break;
            case '=':
                mp[str1]++;
                mp[str2]++;
                break;
            case 'F':
                mp[str2] += 3;
                break;
        }
    }
    vector<pair<string, int>> pair_vec(mp.begin(), mp.end());
    sort(pair_vec.begin(), pair_vec.end(), cmp);
    for (size_t i = 0; i < pair_vec.size(); i++) {
        cout << pair_vec[i].first << endl;
    }
    return 0;
}
