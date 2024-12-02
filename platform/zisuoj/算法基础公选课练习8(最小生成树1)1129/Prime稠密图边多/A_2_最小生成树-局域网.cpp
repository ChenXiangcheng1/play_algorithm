#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <ctime>

using namespace std;

// 邻接表实现优先队列优化Prime算法求最小生成树，逐点遍历。每条边只会进出优先队列一次，O(E*log(E))
// 没有优先队列优化的, 需要(遍历图O(E+V))(或者维护一个邻边表O(V))再从中找出最短横切边。O(E*(E+V))

map<int, int> adj[105];  // 图的每个顶点是有序且相邻的，所以用随机迭代器[]，相邻顶点用map，所以图用map[]数组表示。undered_map哈希表比map红黑树速度更快但是空间更慢
bool visited[105];  // true表示已经加入到mst最小生成树
typedef struct edge{
    int v, w, weight;

    edge() {};
    edge(int x, int y, int z) : v(x), w(y), weight(z) {}

    bool operator<(const edge o) const {
        return weight > o.weight;
    }
}WeightEdge;
priority_queue<WeightEdge> pq;

int main()
{
    freopen("1569 test0.in", "r", stdin);
    clock_t startTime = clock();
    // 建图
    int n, t, tot = 0, sum = 0;  // tot表示总费用，sum表示最小生成树总费用
    cin >> n >> t;
    while (t--) {  // O(E*log(V))
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].insert(make_pair(b, w));
        adj[b].insert(make_pair(a, w));
        tot += w;
    }

    // Prim算法求最小生成树
    visited[1] = true;
    for (map<int, int>::iterator it = adj[1].begin(); it != adj[1].end(); it++) {  // O(V*log(E))
        pq.push(WeightEdge(1, it->first, it->second));
    }
    while (!pq.empty()) {  // 计算时间复杂度不能只看每次循环相乘，要看操作次数和外层循环的关系。Prime算法中每条边只会进出优先队列一次，所以时间复杂度是O(E*logE)
        WeightEdge minEdge = pq.top();  // 最短边
        pq.pop();
        if (visited[minEdge.w])
            continue;
        // 找到最短横切边
        int newv = minEdge.w;
        visited[newv] = true;
        sum += minEdge.weight;
        // 扩展切边
        for (map<int, int>::iterator it = adj[newv].begin(); it != adj[newv].end(); it++) {
            if (!visited[it->first]) {
                pq.push(WeightEdge(newv, it->first, it->second));
            }
        }
    }
    cout << tot- sum << endl;

    clock_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
