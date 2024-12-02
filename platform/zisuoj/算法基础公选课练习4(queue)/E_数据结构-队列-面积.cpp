#include <iostream>

using namespace std;

/**
 * 检测到环后如何计算面积？检测到环，再在环内遍历，很麻烦
 * 另一种方法，可以通过遍历环外顶点，再用减法求环内顶点数，更容易
 */

int grid[10][10];
int R = 10, C = 10;

void dfs(int x, int y) {
    if (x < 0 || x >=R || y < 0 || y >= C || grid[x][y]) {
        return;
    }
    grid[x][y] = 1;
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x + 1, y);
    dfs(x, y - 1);
}

int main()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        dfs(0, i);
        dfs(9, i);
        dfs(i, 0);
        dfs(i, 9);
    }
    // 打印网格
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (!grid[i][j]) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
