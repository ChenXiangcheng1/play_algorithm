#include <iostream>
#include <algorithm>

using namespace std;

struct edge {
    int x, y, m;
}e[50000];  // 表示边

int cmp(edge a, edge b) {
    return a.m < b.m;
}

int f[305];  // 表示顶点

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{
    int n, k, cnt = 0, maxw = 0;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> e[i].x >> e[i].y >> e[i].m;
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
            cnt++;
            maxw = e[i].m;
            if (cnt == n-1)  // 边比点多，不需要遍历所有的边，只需要遍历点数-1条边就好。感觉可以改成while循环，因为一个联通分量的图中边数>=点数-1，所以Kruskal算法的出口肯定是逐边遍历到n-1为止。
                break;
        }
    }
    cout << n-1 << " " << maxw << endl;
    return 0;
}
