
#include <iostream>
#include <queue>

using namespace std;

/**
 * 图求连通分量个数的问题
 * BFS
 */

int R, C;
int grid[105][105];
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int visited[105][105];

int inArea(int x, int y) {
    return x >=0 && x < R && y >= 0 && y < C;
}

void bfs(int s, int conn_comp_id) {
    queue<int> que;
    que.push(s);
    int curx = s / C;
    int cury = s % C;
    visited[curx][cury] = conn_comp_id;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        curx = cur / C;
        cury = cur % C;
        for (int d = 0; d < 4; d++) {
            int nextx = curx + dirs[d][0];
            int nexty = cury + dirs[d][1];
            if (inArea(nextx, nexty) && grid[nextx][nexty] == 1 && !visited[nextx][nexty]) {
                que.push(nextx * C + nexty);
                visited[nextx][nexty] = conn_comp_id;
            }
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
    // 多个连通分量情况的dfs，需要每个顶点都执行一次dfs，bfs需要参数表示起始顶点
    int conn_comp_cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                conn_comp_cnt++;
                bfs(i*C+j, conn_comp_cnt);
            }
        }
    }
    cout << conn_comp_cnt << endl;
    return 0;
}
