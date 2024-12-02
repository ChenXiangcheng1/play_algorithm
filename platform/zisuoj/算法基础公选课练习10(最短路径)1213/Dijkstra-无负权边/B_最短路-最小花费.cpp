#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[2010][2010];
double dis[2010];
bool visited[2010];

int main()
{
    cin >> n >> m;
    memset(adj, -1, sizeof(adj));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int s, t;
    cin >> t >> s;
    visited[s] = true;

    for (int i = 1; i <= n; i++) {
        if (adj[s][i] == -1) dis[i] = 1e30;
        else dis[i] = 100 / (1-adj[s][i]*1.0/100);
    }


//  for (int i =1; i <= n; i++) {
//      printf("init_dis: %.8lf\n", dis[i]);
//  }

    for (int i = 1; i <= n; i++) {
        int mini = -1;
        double mind = 1e30;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dis[j] < mind) {
                mind = dis[j];
                mini = j;
            }
        }

//      cout << "add:" << mini << " " << mind << endl;
        visited[mini] = true;
        if (mini == t)
            break;


        for (int j = 1; j <= n; j++) {
            if (!visited[j] && adj[mini][j] != -1)  // 索引用错了，是j不是i，又找了半天
//              cout << mini << "\'" << "adj:" << j << " cost: " << adj[mini][i] << endl;
            if (!visited[j] && adj[mini][j] != -1 && mind / (1-adj[mini][j]*1.0/100) < dis[j]) {
                dis[j] = mind / (1-adj[mini][j]*1.0/100);
//              cout << "new: " << dis[j] << endl;
            }
        }
    }
    printf("%.8lf\n", dis[t]);
    return 0;
}
