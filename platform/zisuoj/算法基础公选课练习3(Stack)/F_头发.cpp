#include <iostream>

using namespace std;

// 80000的数据量，至少需要O(n*sqrt(n))或者O(n*logn)级时间复杂度的算法
// 思路1，这其实是一个比较的过程，那么想想可以怎么用栈或者递归并保存递归结果做呢
// 思路2：找i右边大于等于i高度的位置，即为单调栈

const int N = 80050;
int n, heights[N], sarr[N], f[N];

int fun(int ind) {
    int ret = 0;
    // 递归终止条件
    if (ind == n - 1) {
        return 0;
    } else if (f[ind] == 1) {
        return sarr[ind];
    }
    // 调用递归过程
    int maxind = -1;
    for (int j = ind+1; heights[ind] > heights[j] && j < n; j++) {
        if (maxind == -1 || heights[maxind] <= heights[j]) {
            maxind = j;
            ret = ret + fun(j) + 1;
        }
    }
    sarr[ind] = ret;
    f[ind] = 1;
    return ret;
}

int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for (int i = 0; i < n; i++) {
        fun(i);
    }
    for (int i = 0; i < n; i++) {
        sum += sarr[i];
    }
    cout << sum << endl;
    return 0;
}
