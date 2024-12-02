#include <bits/stdc++.h>

using namespace std;

// 最小生成森林

int n, m;
double ans = 0;

int x[1010], y[1010];

int k = 0, cnt = 0;
struct edge {
    int u, v;
    double w;

    bool operator<(const edge o) const {
        return w < o.w;
    }
}e[500100];

int fa[1010];
int find(int p) {
    return p == fa[p] ? p : find(fa[p]);
}

double calc(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; j++) {  // 暴力建边
            e[k].u = i;
            e[k].v = j;
            e[k++].w = calc(x[i], y[i], x[j], y[j]);
        }
    }
    sort(e, e+k);
    for (int i = 0; i < k; i++) {
        int uRoot = find(e[i].u);
        int vRoot = find(e[i].v);
        if (uRoot != vRoot) {
            if (cnt >= n-m) {  // 部落数量达到m个
                ans = e[i].w;
                break;
            }
            fa[uRoot] = vRoot;
            cnt++;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
