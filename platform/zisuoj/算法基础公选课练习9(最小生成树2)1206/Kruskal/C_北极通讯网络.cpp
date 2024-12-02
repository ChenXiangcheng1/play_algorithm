#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 北极通讯网络
/*
	需要分配卫星设备的同时使剩下的顶点的边的最大权值最小，即最小生成树中权值大的边顶点分配卫星设备
	不可以使用prime算法，因为prime求出最小生成树后再排序分配卫星设备不能保证最小生成树的第n-k条边的权值最小
	prime算法是逐点遍历O(V*log(E))
	kruskal算法是逐边遍历O(E*log(E)+E)，如果对边的权值有要求应该使用kruskal算法
*/

struct edge {
    int v, w;
    double weight;

    bool operator<(const edge o) const {
        return weight < o.weight;
    }
}edges[130000];

int n, k, parent[505], x[505], y[505], num = 0, cnt = 0;
double ans;
int find(int p) {
    return p == parent[p] ? p : parent[p] = find(parent[p]);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    //  计算边，需要O(n^2)的时间复杂度
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; j++) {
            edges[num].v = i;
            edges[num].w = j;
            edges[num].weight = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            // cout << edges[num].weight << endl;
            num++;
        }
    }
    sort(edges, edges+num);
    // 最小生成树有 n-1 条边
    for (int i = 0; cnt < n-k && i < num; i++) {
        int vRoot = find(edges[i].v);
        int wRoot = find(edges[i].w);
        if (vRoot != wRoot) {
            parent[vRoot] = wRoot;
            cnt++;
            ans = edges[i].weight;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}
