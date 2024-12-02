#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// 状态表达：用int表示棋盘状态，每种状态都是图的顶点，状态可以向相邻状态转移。BFS就可以找到最小的状态转移次数

int dirs[2][2] = {{0, 1}, {1, 0}};

// int nn= 0;
// void printN(int n) {
//     if (nn==10) {
//         return;
//     }else {
//         nn++;
//         cout << nn << endl;
//     }
//     for(int i = 15; i >= 0; i--) {
//         cout << ((n & (1 << i)) >> i);
//         if ((16-i)%4==0)
//             cout << "\n";
//     }
//     cout << endl;
// }

// 也可以不用+-采用异或取反的方式
int swap(int cur, int curB, int nextB) {
    int ret = cur;
    if ((cur & (1 << curB)) == 0  && (cur & (1 << nextB)) != 0) {  // curB位为0，nextB位为1
        ret += (1 << curB);
        ret -= (1 << nextB);
    } else if ((cur & (1 << curB)) !=0 && (cur & (1 << nextB)) == 0) {  // curB位为1，nextB位为0
        ret += (1 << nextB);
        ret -= (1 << curB);
    }
    return ret;
}

int bfs(int src, int dest) {
    queue<int> q;
    unordered_map<int, int> visited;
    q.push(src);
    visited[src] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == dest) {
            return visited[cur];
        }
        // 遍历棋盘坐标
        for (int curB = 15; curB >=0; curB--) {
            int curx = (15 - curB) / 4, cury = (15 - curB) % 4;
            for (int d = 0; d < 2; d++) {
                int nextx = curx + dirs[d][0];
                int nexty = cury + dirs[d][1];
                if (nextx >=0 && nextx < 4 && nexty >= 0 && nexty < 4) {
                    int nextB = 15 - (nextx * 4 + nexty);
                    int nextN = swap(cur, curB, nextB);
                    if (visited.find(nextN) == visited.end()) {
                        q.push(nextN);
                        // printN(nextN);
                        visited[nextN] = visited[cur] + 1;
                        if (nextN == dest) {
                            return visited[nextN];
                        }
                    }
                }
            }
        }
    }
    return -1;
}

// 状态转移问题：从初始棋盘到最终棋盘
int main()
{
    int src = 0, dest = 0, ans;
    char ch;
    for(int i = 15; i >= 0; --i) {
        cin>>ch;
        if (ch == '1') {
            src += (1 << i);
        }
    }
    for(int i = 15; i >= 0; --i) {
        cin>>ch;
        if (ch == '1') {
            dest += (1 << i);
        }
    }
    ans = bfs(src, dest);
    if (ans != -1) {
        cout << ans << endl;
    }
    return 0;
}
