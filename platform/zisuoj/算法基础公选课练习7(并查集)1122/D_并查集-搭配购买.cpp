#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// N=1000 所需时间复杂度<=O(n^2)

int v[1005], w[1005], parent[1005];

int find(int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot)
        return;
    parent[qRoot] = pRoot;
    v[pRoot] += v[qRoot];
    w[pRoot] += w[qRoot];
}

int main()
{
    int n, m, c, a, b, dp[1005];
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        unionElements(a, b);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {  // 把vis逻辑放在循环外，这里还能优化为O(n-m)
        if ( i != find(i))
            continue;
        for (int j = c; j >= w[i]; j--) {
            dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
        }
    }
    cout << dp[c] << endl;
    return 0;
}
