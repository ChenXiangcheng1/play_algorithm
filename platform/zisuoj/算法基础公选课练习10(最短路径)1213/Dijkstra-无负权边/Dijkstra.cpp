#include <iostream>
#include <cstring>

using namespace std;

const int sz = 100;
int dist[sz][sz];  // 邻接矩阵

int dijkstra(int s) {
    bool visited[sz];
    memset(visited, false, sizeof(visited));
    visited[s] = true;
    int low[sz];  // 代价表
    for (int i = 1; i <= sz; ++i)
        low[i] = dist[s][i];

    for (int i = 1; i < sz; ++i) {
        int cur = -1, curdis = 0x3f3f3f3f;
        for (int v = 1; v <= sz; ++v) {
            if (!visited[v] && low[v] < curdis) {
                curdis = low[v];
                cur = v;
            }
        }
        if (cur == -1)
            break;  // Dijkstra算法出口1，除了不可达的和计算过的都遍历过了
        visited[cur] = true;
        for (int w = 1; w <= sz; ++w) {
            if (!visited[w] && curdis + dist[cur][w] < low[w])
                low[w] = curdis + dist[cur][w];
        }
    }
    // Dijkstra算法出口2，遍历了n-1次，把所有顶点都计算过最短路径了。其实这出口2逻辑和出口1一样，改成while循环更好。
}

int main()
{

    return 0;
}
