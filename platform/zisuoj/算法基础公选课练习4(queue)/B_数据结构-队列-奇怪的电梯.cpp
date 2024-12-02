#include <iostream>
#include <queue>

using namespace std;

int n, src, dest, k[205], visited[205];

int bfs() {
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    if (src == dest) {
        return visited[src];
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int nextN = cur + k[cur];
        if (nextN <= n && !visited[nextN]) {
            q.push(nextN);
            visited[nextN] = visited[cur] + 1;
            if (nextN == dest) {
                return visited[nextN];
            }
        }
        nextN = cur - k[cur];
        if (nextN > 0 && !visited[nextN]){
            q.push(nextN);
            visited[nextN] = visited[cur] + 1;
            if (nextN == dest) {
                return visited[nextN];
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> src >> dest;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    int ans = bfs();
    if (ans == -1) {
        cout << -1 << endl;
    } else {
        cout << ans -1 << endl;
    }
    return 0;
}
