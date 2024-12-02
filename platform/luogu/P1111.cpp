#include <bits/stdc++.h>

using namespace std;

int n, m, maxd, cnt = 0;

int fa[1005];
int find(int p) {
    return p == fa[p] ? p : find(fa[p]);
}

struct edge {
    int u, v, w;
    bool operator<(const edge o) const {
        return w < o.w;
    }
}e[100010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e, e+m);
    for (int i = 0; i < m && cnt < n; i++) {
        int uRoot = find(e[i].u);
        int vRoot = find(e[i].v);
        if (uRoot != vRoot) {
            fa[vRoot] = uRoot;
            maxd = e[i].w;
            cnt++;
        }
    }
    if (cnt == n-1)
        cout << maxd << endl;
    else
        cout << -1 << endl;
    return 0;
}
