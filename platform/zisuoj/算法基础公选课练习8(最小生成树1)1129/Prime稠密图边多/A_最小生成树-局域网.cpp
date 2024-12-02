#include <iostream>
#include <cstring>
#include <ctime>

#define SUP 0x3f3f3f3f

using namespace std;

// 邻接矩阵实现(没有优先队列的，需要维护邻边表)Prime算法求最小生成树，逐点遍历。O(V*(V+E))

int adj[105][105], dis[105];  // adj表示邻接矩阵0表示不连通  // dis[i]表示最小生成树的到邻点i的最小权值，邻点代价表，可以优化和visited语义合并
bool visited[105];  // true表示已经加入到最小生成树

int main()
{
    freopen("1569 test0.in", "r", stdin);
    clock_t startTime = clock();
    // 建图
    int n, t, tot = 0, sum = 0;  // tot表示总费用，sum表示最小生成树总费用
    cin >> n >> t;
    while (t--) {  // O(E)
        int x, y, z;
        cin >> x >> y >> z;
        adj[x][y] = z;
        adj[y][x] = z;
        tot += z;
    }

    // prim求最小生成树
    visited[1] = true;
    for (int i = 1; i <= n; i++) {
        if (adj[1][i] == 0)  // 0表示不连通
            dis[i] = SUP;
        else
            dis[i] = adj[1][i];
    }
    // memset(dis, 0x3f3f3f3f, sizeof(dis));
    // dis[1] = 0;  // 不能为别的值，因为第一个加入的元素没边，即权值为0

    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << " ";
    // cout << endl;

    for (int i = 2; i <= n; i++) {  // 依次添加n-1个顶点
        int cur = -1, curdis = SUP;
        for (int j = 2; j <= n; j++) {
            if (!visited[j] && dis[j] < curdis) {
                curdis = dis[j];
                cur = j;  // 从dis数组中，找出要加入最小生成树的最短邻边的点j
            }
        }
        if (cur == -1)
            cout << "No mininum vertex." << endl;
        visited[cur] = true;  // 加入生成树
        sum += curdis;
        // cout << "add point:" << min_ind << endl;

        // 维护dis[j]
        for (int j = 2; j <= n; j++) {
            if (!visited[j] && adj[cur][j]!=0 && adj[cur][j] < dis[j])  // 维护dis数组中，最小生成树到没加入生成树的元素的最小费用  // 用优先队列需要删除(vis数组的逻辑)，时间复杂度也差不多（比如队列中有1->2:3 3->2:4,出队1->2后还**需要删除**3->2,或许可以用优先队列while_pop）
                // 这里好像Dijkstra的松弛操作，不过松弛操作是找点对点的最短路，Prim是找最小生成树到点的最短路
                dis[j] = adj[cur][j];
        }
    }
    cout << tot- sum << endl;

    clock_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
