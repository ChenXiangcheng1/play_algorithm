#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

// Dijkstra 迪杰斯特拉。这题**由于只能向右向下**，所以有重叠子问题，可以用dp。

class Solution {
private:
    int R, C;
    int dirs[2][2] = {{1, 0}, {0, 1}};

    struct node
    {
        int x, y, s;

        bool operator<(const node o) const {
            return s > o.s;
        }
    }cur, nextN;

    bool inArea(int x, int y) {
        return x >= 0 && x < R && y >= 0 && y < C;
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        priority_queue<node> que;
        bool vis[R][C];
        memset(vis, false, sizeof(vis));  // 局部变量需要初始化！
        que.push({0, 0, grid[0][0]});
        vis[0][0] = true;
        if( 0 == R-1 && 0 == C-1 ) {
            return grid[0][0];
        }
        while( !que.empty() ) {
            cur = que.top();
            que.pop();
            for( int d = 0 ; d < 2 ; d++ ) {
                int nextx = cur.x + dirs[d][0];
                int nexty = cur.y + dirs[d][1];
                if( inArea(nextx, nexty) && !vis[nextx][nexty] ) {  // 这里一定需要vis标记数组。若没有则会入队(顶点总数*cost的可能性)这么多个顶点，BFS里记录了顶点+当前访问这个顶点的时候的cost信息
                    nextN.x = nextx;
                    nextN.y = nexty;
                    nextN.s = grid[nextx][nexty] + cur.s;
                    que.push(nextN);
                    vis[nextx][nexty] = true;
                    if( nextx == R-1 && nexty == C-1 )
                        return nextN.s;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout<<Solution().minPathSum(vec)<<endl;
    return 0;
}
