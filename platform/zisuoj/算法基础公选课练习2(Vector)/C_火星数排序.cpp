#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ivec;

int level(int a) {
    switch (a) {
        case 0:
            return 0;
            break;
        case 8:
            return 1;
            break;
        case 1:
            return 2;
            break;
        case 5:
            return 3;
            break;
        case 2:
            return 4;
            break;
        case 3:
            return 5;
            break;
        case 9:
            return 6;
            break;
        case 4:
            return 7;
            break;
        case 7:
            return 8;
            break;
        case 6:
            return 9;
            break;
        default:
            cout << "No define the number's priority level." << endl;
            return -1;
    }
}

bool cmp(int a, int b) {
    vector<int> veca, vecb;
    while (a) {
        veca.push_back(a % 10);
        a /= 10;
    }
    while (b) {
        vecb.push_back(b % 10);
        b /= 10;
    }
    if (veca.size() == vecb.size()) {
        for (size_t i = veca.size()-1; i >= 0; i--) {
            if (level(veca[i]) == level(vecb[i])) {
                continue;
            } else {
                return level(veca[i]) < level(vecb[i]);
            }
            return false;
        }
    } else {
        return veca.size() < vecb.size();
    }
}

int main()
{
    int t, n, tmp;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            ivec.push_back(tmp);
        }
        sort(ivec.begin(), ivec.end(), cmp);
        for (size_t i = 0; i < ivec.size(); i++) {
            if (i != 0) {
                cout << " ";
            }
            cout << ivec[i];
        }
        cout << endl;
        ivec.clear();
    }
    return 0;
}
