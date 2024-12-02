#include <iostream>
#include <algorithm>

using namespace std;

struct edge {
    int x, y, m;
}e[5005];  // (1+n-1)*(n-1)/2

int cmp(edge a, edge b) {
    return a.m < b.m;
}

int f[105];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{
    int n, k, tot = 0, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> e[i].x >> e[i].y >> e[i].m;
        tot += e[i].m;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    sort(e, e+k, cmp);
    for (int i = 0; i < k; i++) {
        int xRoot = find(e[i].x);
        int yRoot = find(e[i].y);
        if (xRoot != yRoot) {
            f[xRoot] = yRoot;
            sum += e[i].m;
        }
    }
    cout << tot - sum << endl;
    return 0;
}
