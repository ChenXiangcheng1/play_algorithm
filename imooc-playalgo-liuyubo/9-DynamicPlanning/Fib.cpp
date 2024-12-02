#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> memo;
int num;

// 完全递归的时间复杂度：O(2^n)
// 记忆化搜索，记录递归搜索结果的时间复杂度：O(2n)
// 该怎么搜索？这样搜索怎样可以做记忆化？
int fib( int n ){

    num ++;

    if ( n == 0 )
        return 0;

    if ( n == 1 )
        return 1;

    if ( memo[n] == -1 )
        memo[n] = fib(n-1) + fib(n-2);

    return memo[n];
}

/**
 * 递归和**记忆化搜索**都是自上而下的解决问题，**动态规划**是自下而上的解决问题。
 * 如何定义状态和状态转移
 *
 * 记忆化搜索和动态规划一样，解决的都是有重叠子问题的递归问题
 */
int fib_dp( int n ){

    vector<int> memo(n+1, -1);

    memo[0] = 0;
    memo[1] = 1;
    for( int i = 2; i <= n ; i ++ )
        memo[i] = memo[i-1] + memo[i-2];

    return memo[n];
}

int main() {

    num = 0;

    int n = 10000;
    memo = vector<int>(n+1, -1);

    time_t startTime = clock();
    int res = fib(n);  // 47
    time_t endTime = clock();

    cout<<"fib("<<n<<") = "<<res<<endl;
    cout<<fixed<<"time : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    cout<<"run function fib() "<<num<<"times."<<endl;

    return 0;
}
