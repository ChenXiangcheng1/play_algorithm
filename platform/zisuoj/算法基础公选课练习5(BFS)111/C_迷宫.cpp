#include <iostream>
#include <queue>

#define N 105

using namespace std;

char grid[N][N];
int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int R, C;
int visited[N][N];

int k, x1, y1, x2, y2;

bool inArea(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

struct node
{
    int x, y, c;
    bool operator<(const node o) const
    {
        return c > o.c;
    }
} cur, nextN;

bool bfs()
{
    priority_queue<node> q; // 需要保证第一次遍历(pop)到的是转弯次数最少的路径，出队的是转弯次数最少的点
                            // **需要在转弯后标记同方向所有可以走到的点，保证了下次入队的是之前没走过的点，保证了最队的next.c是次数最少的**
    cur.x = x1;
    cur.y = y1;
    cur.c = -1;
    q.push(cur);
    visited[x1][y1] = 1;
    while (!q.empty())
    {
        cur = q.top();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nextx = cur.x + dirs[d][0];
            int nexty = cur.y + dirs[d][1];
            // 转弯后向该方向一直走，可以重复走到同一点
            while (inArea(nextx, nexty) && grid[nextx][nexty] != '*')
            {
                if (!visited[nextx][nexty]) {
                    nextN.x = nextx;
                    nextN.y = nexty;
                    nextN.c = cur.c + 1;
                    q.push(nextN);
                    visited[nextx][nexty] = 1;  // 转弯后，标记可以走到的点(这些点的最小转弯次数都是cur.c+1)
                }
                if (nextx == x2 && nexty == y2 && nextN.c <= k)
                {
                    return true;
                }
                nextx += dirs[d][0];
                nexty += dirs[d][1];
            }
        }
    }
    return false;
}

// 路径搜索问题
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> grid[i][j];
                visited[i][j] = 0;
            }
        }
        cin >> k >> y1 >> x1 >> y2 >> x2;
        x1--;
        y1--;
        x2--;
        y2--;
        if (bfs())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
