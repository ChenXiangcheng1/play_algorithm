#include <iostream>
#include <vector>

using namespace std;

// n=10000 所需时间复杂度<=O(n*sqrt(n))

// 12 = 9 1 1 1
// 12 = 4 4 4  // 所以不能用贪心

class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n+1);
        memo[0] = 0;
        for( int i = 1 ; i <= n ; i ++ ) {  // 子问题
            int min_memo = INT_MAX;
            for ( int j = 1 ; j*j <= i ; j ++ ) {  // n^2的dp还是会时间溢出，需要优化到nlogn。  // TLE说明状态转移方程还不够时间复杂度优化。
                min_memo = min(min_memo, 1 + memo[i-j*j]);
            }
            memo[i] = min_memo;
        }
        // for( int i = 1 ; i <= n ; i ++ )
        //     cout<<memo[i]<<endl;
        return memo[n];
    }
};

int main()
{
    cout<<Solution().numSquares(12)<<endl;
    cout<<Solution().numSquares(13)<<endl;
    return 0;
}
