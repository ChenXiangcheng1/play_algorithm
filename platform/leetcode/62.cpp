#include <iostream>
#include <vector>

using namespace std;

// N=10000 所需时间复杂度<=O(n*sqrt(n))

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    cout<<Solution().uniquePaths(3, 7)<<endl;
    cout<<Solution().uniquePaths(3, 2)<<endl;
    cout<<Solution().uniquePaths(7, 3)<<endl;
    cout<<Solution().uniquePaths(3, 3)<<endl;
    return 0;
}
