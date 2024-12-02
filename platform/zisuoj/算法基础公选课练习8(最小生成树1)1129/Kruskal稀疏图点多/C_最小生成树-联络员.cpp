#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct edge{
    int v, w, weight;
}edges[10050];

int cmp(edge a, edge b) {
    return a.weight < b.weight;
}

int parent[2050];

int find(int p) {
    if (p != parent[p]) {
        parent[p] = find(parent[p]);
    }
    return parent[p];
}

int main() {
    int n, m, k = 0, cnt = 0;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        int p, v, w, weight;
        cin >> p >> v >> w >> weight;
        if (p == 1) {
            int vRoot = find(v);
            int wRoot = find(w);
            if (vRoot != wRoot) {
                parent[vRoot] = wRoot;
                cnt++;
            }
            ans += weight;
        } else {
            edges[k].v = v;
            edges[k].w = w;
            edges[k].weight = weight;
            k++;
            // cout << "adding edge: "<< v << w << weight << endl;
            // cout << "added edge: " << k << " " << edges[k].v << " " << edges[k].w << " " << edges[k].weight << endl;
        }
    }
    sort(edges, edges+k, cmp);
    // for (int i = 0; i < k; i++)
    //     cout << "edges: " << edges[i].v << " " << edges[i].w << " " << edges[i].weight << endl;
    // cout << "ans: " << ans << endl;
    for (int i = 0; i < k; i++) {
        int vRoot = find(edges[i].v);
        int wRoot = find(edges[i].w);
        if (vRoot != wRoot) {
            // cout << "merge: " << i << " " << edges[i].v << " " << edges[i].w << " " << edges[i].weight << endl;
            parent[vRoot] = wRoot;
            ans += edges[i].weight;
            cnt++;
            if (cnt == n-1)
                break;
        }
    }
    cout << ans << endl;
}
