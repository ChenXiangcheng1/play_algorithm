#include <iostream>

using namespace std;

int arr[500100];

int main()
{
    int n, k, l = 1, r, resl = 0, resr = -1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    while (l <= n) {
        if (arr[l] <= k) {
            r = l+1;
            while (r <= n && arr[r] <= k) {
                r++;
            }
            if (r-l > resr - resl) {
                resr = r;
                resl = l;
            }
            l = r;
        } else {
            l++;
        }
    }
    cout << resl << " " << resr-1 << endl;
    return 0;
}
