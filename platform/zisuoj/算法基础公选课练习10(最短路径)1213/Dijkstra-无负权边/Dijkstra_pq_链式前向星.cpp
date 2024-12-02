#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int sz = 100;
const int MAXM = 5000;

// 链式前向星，使用数组模拟邻接表的方法。如果有O2优化还是用vector<map>更好，如果没有可以选择链式前向星
struct ty {  // Treey
    int t;  // 目标顶点编号
    int w;  // 边的权值
    int next;  // 下一条边的编号

    bool operator<(const ty o) const {
        return w > o.w;
    }
} edge[MAXM];

int head[MAXM];  // head[i]表示从顶点i出发的第一条边在edge[]中的位置

int dijkstra_priority_queue(int n) {
    bool visited[sz];
    memset(visited, false, sizeof(visited));
    int dis[sz];  // 代价表
    memset(dis, 127, sizeof(dis));
    priority_queue<ty> pq;
    visited[1] = true;
    dis[1] = 0;
    for (int i = head[1]; i != 0; i = edge[i].next) {  // i边编号: 从顶点1开始的第一条边的编号开始遍历其每一条边
        if (edge[i].w < dis[edge[i].t]) {
            dis[edge[i].t] = edge[i].w;
            pq.push(edge[i]);
        }
    }
    ty t2;
    while (!pq.empty()) {
        ty t1 = pq.top();  pq.pop();
        if (visited[t1.t])
            continue;
        visited[t1.t] = true;  // 已经计算出了t1.t的最短路径
        for (int j = head[t1.t]; j != 0; j = edge[j].next) {  // 遍历t1.t开始的所有边
            int u = edge[j].t;
            if (!visited[u] && dis[t1.t] + edge[j].w < dis[u]) {  //  松弛操作
                dis[u] = dis[t1.t] + edge[j].w;
                t2.t = u;
                t2.w = dis[u];
                t2.next = 0;
                pq.push(t2);  // 松驰过的顶点都入队
            }
        }
    }
    cout << dis[n] << endl;
}

int main()
{

    return 0;
}
