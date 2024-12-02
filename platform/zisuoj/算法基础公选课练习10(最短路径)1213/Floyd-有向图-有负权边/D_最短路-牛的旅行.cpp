#include <bits/stdc++.h>

#define SUP 0x7f7f7f7f

using namespace std;

// 求连接不同路径得到的新联通分量中的最小直径（联通分量的直径是分量中最远两点的距离）

int n, x[155], y[155];
char adj[155][155];

double dis[155][155];
double maxd[155];

double getWeight(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    // freopen("D_in.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // Floyd算法
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == '1' || i == j) {  // adj[i][j] == '1' || i == j 表示相邻
                dis[i][j] = getWeight(x[i], y[i], x[j], y[j]);
            } else {
                dis[i][j] = SUP;
            }
        }
    }
    for (int t = 0; t < n; t++) {
        for (int v = 0; v < n; v++) {
            for (int w = 0; w < n; w++) {
                if (dis[v][t] != SUP && dis[t][w] != SUP && dis[v][t] + dis[t][w] < dis[v][w]) {
                    dis[v][w] = dis[v][t] + dis[t][w];
                }
            }
        }
    }

    // 求连接不同路径得到的新联通分量中的最小直径（联通分量的直径是分量中最远两点的距离）（连接i-j后，新联通分量的直径 = maxd[i]+dist(i,j)+maxd[j]）
    for (int i = 0; i < n; i++) {
        maxd[i] = -SUP;  // i起点的最大直径
        for (int j = 0; j < n; j++) {
            if (dis[i][j] != SUP && dis[i][j] > maxd[i]) {  // dis[i][j] != SUP 表示可达
                maxd[i] = dis[i][j];
            }
        }
    }

    double ans1 = -SUP;
    for (int i = 0; i < n; i++) {
        if (maxd[i] > ans1) {
            ans1 = maxd[i];  // 多个旧连通分量中的最大直径  // 12.0711
        }
    }

    // 连接i-j后，新联通分量的直径 = maxd[i]+dist(i,j)+maxd[j]
    double ans2 = SUP;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double tmp = maxd[i] + getWeight(x[i], y[i], x[j], y[j]) + maxd[j];  // 不连通时dist[i][j]=SUP, 需要重新未计算
            if (dis[i][j] == SUP && tmp < ans2) {  // 需要原来不可达的
                ans2 = tmp;
            }
        }
    }

    printf("%.6lf\n", max(ans1, ans2));
    return 0;
}
