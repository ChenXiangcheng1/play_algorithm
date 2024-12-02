#include <iostream>
#include <vector>

using namespace std;

// DP 时间复杂度：O(m*n)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t R = grid.size();
        size_t C = grid[0].size();
        vector<vector<int>> vis(R, vector<int>(C, -1));
        vis[0][0] = grid[0][0];
        for( size_t i = 1 ; i < C ; i++ ) {
            vis[0][i] = grid[0][i] + vis[0][i-1];
        }
        for( size_t i = 1 ; i < R ; i++ ) {
            vis[i][0] = grid[i][0] + vis[i-1][0];
        }
        for( size_t i = 1 ; i < R ; i++ ) {
            for( size_t j = 1 ; j < C ; j++ ) {
                vis[i][j] = grid[i][j] + min(vis[i-1][j], vis[i][j-1]);
            }
        }

        // for( size_t i = 0 ; i < R ; i++ ) {
        //     for( size_t j = 0 ; j < C ; j++ ) {
        //         if( j != 0 )
        //             cout<<" ";
        //         cout<<vis[i][j];
        //     }
        //     cout<<endl;
        // }

        return vis[R-1][C-1];
    }
};

int main()
{
    vector<vector<int>> vec({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    cout<<Solution().minPathSum(vec)<<endl;
    return 0;
}
