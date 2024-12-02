#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int grid[105][105];
int R = 100, C = 100;
int dirs[12][2] = {{-2, 1}, {-2, 2}, {-1, 2}, {1, 2}, {2, 2}, {2, 1}, {2, -1}, {2, -2}, {1, -2}, {-1, -2}, {-2, -2}, {-2, -1}};
int vis[105][105];

int inArea(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

int bfs(int x, int y) {
	queue<int> q;
	q.push(x * C + y);
	vis[x][y] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int curx = cur / C;
		int cury = cur % C;
		for (int d = 0; d < 12; d++) {
			int nextx = curx + dirs[d][0];
			int nexty = cury + dirs[d][1];
			if (inArea(nextx, nexty) && vis[nextx][nexty] == -1) {  // vis==1表示没有走过，不要写错了
				q.push(nextx * C + nexty);
				vis[nextx][nexty] = vis[curx][cury] + 1;
				if (nextx == 0 && nexty == 0) {
					return vis[nextx][nexty];
				}
			}
		}
	}
	return -1;
}

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	memset(vis, -1, sizeof(vis));  // 初始化二维数组
	int ans1 = bfs(x1-1, y1-1);
	memset(vis, -1, sizeof(vis));
	int ans2 = bfs(x2-1, y2-1);
	cout << ans1 << "\n" << ans2 << endl;
	return 0;
}
