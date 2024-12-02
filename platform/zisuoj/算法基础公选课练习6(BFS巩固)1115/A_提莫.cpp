#include <iostream>
#include <queue>

using namespace std;

int n, m;
int vis[200005];  // 未访问状态设为false -1更好 
queue<int> q;

int bfs() {
	vis[n] = 1;	
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int nextN = cur + 1;
		if (nextN <= 200000 && !vis[nextN]) {
			q.push(nextN);
			vis[nextN] = vis[cur] + 1;
			if (nextN == m) {
				return vis[nextN] - 1;
			}
		}
		nextN = cur - 1;
		if (nextN > 0 && !vis[nextN]) {
			q.push(nextN);
			vis[nextN] = vis[cur] + 1;
			if (nextN == m) {
				return vis[nextN] - 1;
			}
		}
		nextN = cur * 2;
		if (nextN <= 200000 && !vis[nextN]) {
			q.push(nextN);
			vis[nextN] = vis[cur] + 1;
			if (nextN == m) {
				return vis[nextN] - 1;
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	int ans = bfs();
	cout << ans << endl;
	return 0;
}
