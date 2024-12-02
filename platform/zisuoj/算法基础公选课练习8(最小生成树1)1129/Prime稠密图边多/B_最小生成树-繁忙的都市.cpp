#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// 这题应该用kruskal算法，逐边遍历，不过这题测试用例太松了

const int maxn = 305;
map<int, int> adj[maxn];
bool visited[maxn];
typedef struct edge {
    int v, w, weight;

    edge() {}
    edge(int x, int y, int z) : v(x), w(y), weight(z) {}
    bool operator<(const edge o) const {
        return weight > o.weight;
    }
}WeightEdge;
priority_queue<WeightEdge> pq;

int main()
{
    int n, t, cnt = 0, max_w = -1;
    cin >> n >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].insert(make_pair(y, z));
        adj[y].insert(make_pair(x, z));
    }
    visited[1] = true;
    for (map<int, int>::iterator it = adj[1].begin(); it != adj[1].end(); it++) {
        pq.push(WeightEdge(1, it->first, it->second));
    }
    while (!pq.empty()) {
        WeightEdge minEdge = pq.top();
        pq.pop();
        if (visited[minEdge.w])
            continue;
        int newv = minEdge.w;
        visited[newv] = true;
        cnt++;
        max_w = max(max_w, minEdge.weight);
        for (map<int, int>::iterator it = adj[newv].begin(); it != adj[newv].end(); it++) {
            if (!visited[it->first])
                pq.push(WeightEdge(newv, it->first, it->second));
        }
    }
    cout << cnt << " " << max_w << endl;
    return 0;
}
