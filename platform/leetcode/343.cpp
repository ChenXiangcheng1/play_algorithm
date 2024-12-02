#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// 动态规划

class Solution {
private:
    vector<int> memo;

    int max3( int a , int b , int c ) {  // 对使用多个max，封装一个方法
        return max( a , max(b,c) );
    }

    // 将n进行分割(至少分割成两部分)，可以获得的最大成绩
    int breakInteger(int n) {

        if( n == 1 )
            return 1;

        if( memo[n] != -1 )  // 记忆化返回
            return memo[n];

        int res = -1;
        for( int i = 1 ; i <= n-1 ; i ++ )
            res = max3(res, i*(n-i), i * breakInteger(n-i));

        memo[n] = res;
        return res;
    }

public:
    // 递归的记忆化搜索
    int integerBreak_memo(int n) {
        assert( n >= 2);
        memo = vector<int>(n+1, -1);
        return breakInteger(n);
    }

    int integerBreak(int n) {
        assert( n >= 2);
        vector<int> memo(n+1);  // 状态表达：memo[i]表示将数字i分割(至少分割成两部分)后得到的最大面积
        memo[1] = 1;  // 需要给出基本问题的解，相当于记忆化搜索的递归边界

        for( int i = 2 ; i <= n ; i++ ) {  // 自底向上的子问题
            int max_memo = -1;
            for( int j = 1 ; j <= i/2 ; j++ ) {
                max_memo = max(max_memo, max(j, memo[j]) * max(i-j, memo[i-j]));
            }
            memo[i] = max_memo;  // 递推的状态转移
        }

        // for( int i = 1 ; i <= n ; i++ ) {
        //     cout<<memo[i]<<" ";
        // }
        // cout<<endl;

        return memo[n];  // 返回原问题的解
    }
};

int main()
{
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}
