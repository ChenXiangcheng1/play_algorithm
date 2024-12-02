#include <stdio.h>
#include <Math.h>
#include <vector>

using std::vector;

/*
素数筛：是一种快速“筛”出2~n之间所有素数的方法。(筛掉不是素数的数)。需要指出的是1既不是素数也不是合数
*/

#define MAXN 1000
int isnp[MAXN];  // is not prime,初始全0

// 最简易的方法：对所有小于自身的数进行求余
// 思路：从2~n，筛去整除小于其自身的数(有因子，不是素数，筛掉)
// 时间复杂度：O(n*logn)
void simple_fun(int n){
    for(int i=2;i<=n;i++){
        int j;
        for(j=2;j*j<=i;j++)
            if(i%j==0)
                isnp[i]=1;
    }
}

// 埃氏筛(埃拉托色尼筛) the Sieve ofEratosthenes。是一种朴素的筛法。
// 思路：从2~sqrt(n)，**筛去素数的倍数**(其倍数不是素数，筛掉)。埃氏筛中同一个数可能被多个素数筛到。
// 时间复杂度：O(nlogn)，证明需要用到收敛
void sieve(int n){
    for(int i=2;i*i<=n;i++){  // i能筛掉的最小的数是i*i,要<=n才有意义
        if(!isnp[i])
            for(int j=i*i;j<n;j+=i)
                isnp[j]=1;
    }
}

// 欧拉筛，也叫线性筛。
// 思路：让每一个合数(不是素数的数)被其最小质因数筛到。
// 时间复杂度：O(n)
vector<int> primes; // 质数表
void init(int n)
{
    for (int i = 2; i <= n; i++) // 总体的时间复杂度是O(n): 每次筛掉 i*素数。最坏情况是筛掉i*素数表中的所有素数(n个)，该循环最坏时间复杂度O(n)均摊给n个数的操作后的时间复杂度是O(1)
    {
        if (!isnp[i])
            primes.push_back(i);  // 维护素数表
        for (int p : primes)
        {
            if (p * i > n)  // 索引检查
                break;
            isnp[p * i] = 1;
            if (i % p == 0)  // 当p是i的最小质因数(p能整除i)时停止遍历质数表，因为被比p大的素数筛掉的数(i*p')的最小质因数一定是p
                break;
        }
    }
}

int main(){

    return 0;
}
