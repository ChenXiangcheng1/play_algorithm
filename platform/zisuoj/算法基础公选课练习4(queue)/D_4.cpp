#include <iostream>

using namespace std;

int grid[105][105];
int dirs[4][2] = {{0, 1}, {1, 0}};
int R, C;
int parent[10050], sz[10050];

int find(int p) {
    if (p != parent[p]) {
        parent[p] = find(parent[p]);  // 路径压缩
    }
    return parent[p];
}

void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot) {
        return;
    }
    parent[pRoot] = qRoot;
    sz[qRoot] += sz[pRoot];
}

bool inArea(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C; 
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    for (int v = 0; v < R * C; v++) {
        parent[v] = v;
        sz[v] = v;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j]) {
                for (int d = 0; d < 2; d++) {
                    int nextx = i + dirs[d][0];
                    int nexty = j + dirs[d][1];
                    if (inArea(nextx, nexty) && grid[nextx][nexty]) {
                        unionElements(nextx * C + nexty, i * C + j);
                        // 打印根
                        // for (int v = 0; v < R * C; v++) {
                        //     cout << parent[v] << " ";
                        // }
                        // cout << endl;
                    }
                }
            }
        }
    }
    int conn_comp_cnt = 0;
    for (int v = 0; v < R * C; v++) {
        int x = v / C;
        int y = v % C;
        if (grid[x][y] && v == find(v)) {
            conn_comp_cnt++;
        }
    }
    cout << conn_comp_cnt << endl;
    return 0;
}
