#include <iostream>

using namespace std;

/**
 * 图求连通分量个数的问题
 * DFS
 */

int R, C;
int grid[105][105];
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int visited[105][105];

int inArea(int x, int y) {
    return x >=0 && x < R && y >= 0 && y < C;
}

// 递归dfs
void dfs(int v, int conn_comp_id) {
    int curx = v / C;
    int cury = v % C;
    visited[curx][cury] = conn_comp_id;
    for (int d = 0; d < 4; d++) {
        int nextx = curx + dirs[d][0];
        int nexty = cury + dirs[d][1];
        if (inArea(nextx, nexty) && grid[nextx][nexty] == 1 && !visited[nextx][nexty]) {
            dfs(nextx * C + nexty, conn_comp_id);
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    // 多个连通分量情况的dfs，需要每个顶点都执行一次dfs
    int conn_comp_cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                conn_comp_cnt++;
                dfs(i*C+j, conn_comp_cnt);
            }
        }
    }
    cout << conn_comp_cnt << endl;
    return 0;
}
