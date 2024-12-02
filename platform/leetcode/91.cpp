#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

// n=100 所需时间复杂度<=O(n^4)

class Solution {
private:
    int n;
    vector<int> dp;

    /**
     * 总结：
     * 感觉我子串**状态的定义有点问题**，导致**状态转移方程也有问题**
     * 如何遍历所有的可能性(状态转移方程)应该是[i,len)=[i+1,len)+[i+2,len)，而不是[i,j]=[i,k]*[k+1,j]（乘积的方式无法遍历所有可能性）
     * 如果下次dp出问题，可以先思考如何构建正确的解空间树(再可以先通过写回溯搜索版题解，思考如何能正确的遍历所有可能性)，再去写DP版题解。
     */

    // 返回 s[i...len) 所能表示解码数量。解空间树是[i,len)的逻辑子串，解空间树孩子节点的关系应该是sum，乘积关系无法构建正确的解空间树
    int dfs(const string& s, int start) {  // 整串+开始索引表示状态(逻辑子串[start,len) )
        // 这里也有问题，怎么搜索能遍历所有的可能性，[i,j]子串显然不能

        // 递归终止条件
        if (start >= s.size())
            return 1;

        if (s[start] == '0')
            return 0;
        if (dp[start] != -1)
            return dp[start];
        // 调用递归
        int res = dfs(s, start + 1);
        if (start + 1 < n && s.substr(start, 2) <= "26")  // 若逻辑子串不是单字符
            res += dfs(s, start + 2);
        dp[start] = res;
        return res;
    }

public:
    int numDecodings_memo(string s) {
        n = s.size();
        dp = vector<int>(n, -1);
        return dfs(s, 0);
    }

    // **状态定义**： dp[i] 表示用s[i...len)所能表示的方法数。
    int numDecodings(string s) {

        int n = s.size();
        if (n == 1 || s[0] == '0')
            return s[0] != '0';

        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') {
                dp[i] = dp[i + 1];  //
                if (i + 1 < n && s.substr(i, 2) <= "26")
                    dp[i] += dp[i+2];  // 关键是状态转移方程
            }
        }
        return dp[0];
    }

    // 状态定义为[i,j]的子串，不知道如何处理边界(遍历所有可能性有问题)，错误了
    int numDecodings_dp(string s) {
        int len = s.size();
        vector<vector<int> > memo(len, vector<int>(len, 0));
        for( int i = 0 ; i < len ; i ++ ) {
            if (s[i] != '0')
                memo[i][i] = 1;
        }
        for( int i = 0 ; i < len - 1 ; i++ ) {
            if( s[i] == '0' ) {
                memo[i][i+1] = 0;
                continue;
            }
            int t = (s[i] - '0') * 10 + s[i+1] - '0';
            if( t >= 1 && t <= 26 && s[i+1]!= '0' )
                memo[i][i+1] = 2;
            else
                memo[i][i+1] = 1;
        }
        for( int i = len-1 ; i >= 0 ; i -- ) {
            for( int j = i+2 ; j <= len-1 ; j ++ ) {  // 子问题：[i, j]的串
                int max_memo = -1;
                for( int k = 0 ; k <= 1 && i+k+1<=j ; k ++) {
                    max_memo = max(max_memo, memo[i][i+k]*memo[i+k+1][j]);  // 现在状态转移方程的子问题乘积的关系，乘积后再加上左右的情况。1想想有没有直接关系是+加的状态转移方式(子串乘，整串加，没有整串的递归子问题,**有，bfs保存整串和start开始索引两个信息**)，2或者别的状态表达方式(状态就是子串)，3再或者继续去处理加的情况。
                }
                memo[i][j] = max_memo;
                for( int k = i ; k <= j && s[k] !='0' ; k ++ ) {
                    if( k == j )
                        memo[i][j]++;  // 这++的情况不好判断，分割的左右点若可以组成正确编码则需要++。应该就是这里有问题了，左右可以组成正确编码应该如何表达
                }
            }
        }

        // for( int i = 0 ; i <= len-1 ; i++ ) {
        //     for ( int j = 0 ; j <= len -1 ; j++ ) {
        //         if( j != 0)
        //             cout<<" ";
        //         cout<<memo[i][j];
        //     }
        //     cout<<endl;
        // }

        return memo[0][len-1];
    }
};

int main()
{
    cout<<Solution().numDecodings("12")<<endl;
    cout<<Solution().numDecodings("226")<<endl;
    cout<<Solution().numDecodings("0")<<endl;
    cout<<Solution().numDecodings("06")<<endl;
    cout<<Solution().numDecodings("1201234")<<endl;
    return 0;
}
