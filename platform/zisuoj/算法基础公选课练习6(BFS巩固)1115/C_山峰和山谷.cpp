#include <iostream>
#include <queue>

using namespace std;

// 如果有更高的就去遍历更高的，
// 1000*1000的地图，DFS深度太大，要使用BFS。记录周围点的大小情况，如果不一致就标记。

const int maxn = 1005;
int grid[maxn][maxn];
int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
// int dir[][2]{0,1,0,-1,1,0,-1,0,1,-1,-1,-1,-1,1,1,1};  // C++ 数组的定义方式
int N;
bool vis[maxn][maxn];
int valley_ans, peak_ans;  // 表示峰谷的数量

int inArea(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

// 和一般BFS不同的是，同高度则遍历，并每点需要和周围点比较，再根据产生的标志位isPeak isValley判断这片区域是山峰还是山谷
void bfs(int x, int y) {
	bool isPeak = false;  // 表示每个cur比周围点nextN高
	bool isValley = false;  // 表示每个cur比周围点nextN低
	queue<int> que;  // 取名为que更好
	que.push(x * N + y);
	vis[x][y] = true;
	int cnt = 1;  // 同高度的数量
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		int curx = cur / N;
		int cury = cur % N;
		for (int d = 0; d < 8; d++) {
			int nextx = curx + dirs[d][0];
			int nexty = cury + dirs[d][1];
			if (inArea(nextx, nexty)) {
				// 剪枝，如果访问过并且高度相等，说明是属于从同一点出发的BFS已经遍历过的点
				if (vis[nextx][nexty] && grid[curx][cury] == grid[nextx][nexty]) {
					continue;
				}
				// cout << nextx << ":" << nexty << endl;
				if (grid[curx][cury] == grid[nextx][nexty]) {
					que.push(nextx * N + nexty);
					vis[nextx][nexty] = true;
					cnt ++;
				} else if (grid[curx][cury] > grid[nextx][nexty]) {
					isPeak = true;
					// cout << 1 << endl;
				} else {
					// cout << curx << cury << ":" << nextx << nexty<< endl;
					isValley = true;
					// cout << 2 << endl;
				}
			}
		}
	}
	// if (isPeak && isValley) {  // 说明不是山峰也不是山谷
	// 	return;
	// }
	// cout << isPeak << isValley << endl;
	if (isPeak && !isValley) {
		peak_ans++;
	} else if (isValley && !isPeak) {
		valley_ans++;
	} else if(cnt == N * N) {  // 既是山峰又是山谷
		peak_ans++;
		valley_ans++;
	}
	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				bfs(i, j);
			}
		}
	}
	// bfs(0, 0);
	cout << peak_ans << " " << valley_ans << endl;
	return 0;
}
