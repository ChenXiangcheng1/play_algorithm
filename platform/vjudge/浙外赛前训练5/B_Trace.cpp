#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, t;
    double res = 0, f = 1.0;
    vector<int> ivec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ivec.push_back(t);
    }
    sort(ivec.begin(), ivec.end(), greater<int>());

    for (int i = 0; i < ivec.size(); i++) {
        res += f * pow(ivec[i], 2) * M_PI;
        f *= -1;
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
