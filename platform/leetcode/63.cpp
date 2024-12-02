#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R = obstacleGrid.size();
        if (!R)
            return 0;
        int C = obstacleGrid[0].size();
        if (!C || obstacleGrid[0][0])
            return 0;
        vector<vector<int> > dp(R, vector<int>(C, 111));  // 若容器的每个元素都有用到，可以初始化为一个不覆盖容易出错的值
        dp[0][0] = 1;
        for (int i = 1; i < R; i++) {
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i-1][0];
        }
        for (int i = 1; i < C; i++) {
            dp[0][i] = obstacleGrid[0][i] ? 0 : dp[0][i-1];
        }

        // 依据遍历顺序forfor，障碍物肯定会先被遍历到
        // for (int i = 1; i < R; i++) {
        //     for (int j = 1; j < C; j++) {
        //         if (obstacleGrid[i][j] == 1)
        //             dp[i][j] = 0;
        //     }
        // }

        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[R-1][C-1];
    }
};

int main()
{
    vector<vector<int> > grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout<<Solution().uniquePathsWithObstacles(grid)<<endl;
    grid = {{0, 1}, {0, 0}};
    cout<<Solution().uniquePathsWithObstacles(grid)<<endl;
    grid = {{1, 0}};
    cout<<Solution().uniquePathsWithObstacles(grid)<<endl;
    grid = {{1, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 0}};
    // cout<<Solution().uniquePathsWithObstacles(grid)<<endl;
    grid = {{},{}};
    cout<<Solution().uniquePathsWithObstacles(grid)<<endl;
    cout<<"End"<<endl;
    return 0;
}
