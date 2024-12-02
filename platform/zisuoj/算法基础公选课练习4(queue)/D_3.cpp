#include <iostream>

using namespace std;

/**
 * 图求连通分量个数的问题
 * DFS优化空间版本
 */

int R, C;
int grid[105][105];

// 递归dfs
void dfs(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || !grid[x][y]) {
        return;
    }
    grid[x][y] = 0;  // 给地图染色
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x + 1, y);
    dfs(x, y - 1);
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
            if (grid[i][j] == 1) {
                conn_comp_cnt++;
                dfs(i, j);
            }
        }
    }
    cout << conn_comp_cnt << endl;
    return 0;
}
