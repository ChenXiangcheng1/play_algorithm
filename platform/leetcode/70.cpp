#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    vector<int> memo;

    // 返回上n阶台阶有多少种方法
    int calcWays(int n){

        if ( n == 0 )  // 若没楼梯可走可是一种方法，那2阶楼梯是2种方法
            return memo[0];

        if ( n == 1 )
            return memo[1];

        // if ( n == 2 )
        //     return 2;

        if ( memo[n] == -1 )
            memo[n] = calcWays(n-1) + calcWays(n-2);
        return memo[n];  // 上n阶楼梯的方法总数 = 上n-1阶楼梯的方法总数+上n-2阶楼梯的方法总数
    }

public:
    int climbStairs(int n) {
        int p = 1, q = 1;
        for (int i = 2 ; i <= n ; i++){
            int tmp = q;
            q += p;
            p = tmp;
        }
        return q;
    }

    int climbStairs_memo(int n) {
        memo = vector<int>(n+1, -1);
        memo[0] = 1;
        memo[1] = 1;
        return calcWays(n);
    }
};

int main()
{
    cout<<Solution().climbStairs(3)<<endl;
    return 0;
}
