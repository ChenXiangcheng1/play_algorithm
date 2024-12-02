#include <iostream>

using namespace std;

// Prim算法要寻找的是离已加入顶点距离最近的顶点； Dijkstra算法是寻找离固定顶点距离最近的顶点
// Prime算法的贪心是没有松弛操作的，计算的是整颗生成树的最小权值，到每个节点不一定是最短路径
// Dijkstra算法的贪心是有松弛操作的，计算的是到每个节点的最小权值
// 所以这题要求的是最短路径尽量小，而不是生成树总权值尽量小，所以应该用Dijkstra算法 O(E*log(E))

#include<bits/stdc++.h>

using namespace std;

int n, m, x[105], y[105];
double adj[105][105];
bool visited[105];
double dis[105];

double calc_dis(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = 1e10;
        }
    }

    int v, w;
    for (int i = 1; i <= m; i++) {
        cin >> v >> w;
        double weight = calc_dis(x[v], y[v], x[w], y[w]);
        adj[v][w] = weight;
        adj[w][v] = weight;
    }

    int s, t;
    cin >> s >> t;

    visited[s] = true;
    for (int i = 1; i <=n; i++) {
        dis[i] = adj[s][i];
    }

    for (int i = 1; i < n; i++) {
        int mini = -1;
        double mind = 1e10;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dis[j] < mind) {
                mind = dis[j];
                mini = j;
            }
        }
//      cout << "add: " << mini << " " << mind  << endl;
        visited[mini] = true;
        if (mini == t)
            break;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && adj[mini][j] != 0 && adj[mini][j] + mind < dis[j]) {
                dis[j] = adj[mini][j] + mind;
            }
        }
    }
    printf("%.2lf\n", dis[t]);
    return 0;
}
