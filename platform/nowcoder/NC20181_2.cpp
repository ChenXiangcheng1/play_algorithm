#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct node
{
    int x, y;
} a[1001];
int Father[1001], n, k;

double Dis(int x, int y)
{
    return (sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y)));
}

int Find(int x)
{
    if (x == Father[x])
        return Father[x];
    Father[x] = Find(Father[x]);
    return Father[x];
}

void Merge(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    Father[fx] = fy;
}

bool check(double len)  // 表示函数
{
    for (int i = 1; i <= n; ++i)
        Father[i] = i;

    for (int i = 1; i <= n - 1; ++i)  // O(V^2) = O(E)
        for (int j = i + 1; j <= n; ++j)
            if (Dis(i, j) <= len && Find(i) != Find(j))
                Merge(i, j);
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (Father[i] == i)
            ++cnt;
    if (cnt < k)
        return false;  // cnt<k; 表示若并查集由cnt个树构成，cnt<k，说明树少了，距离需要扩大r = mid(二分搜索区间选大的)
    else
        return true;  // cnt>=k; 说明树多了或正合适(可以满足要求，按len分至少k个集合)，距离需要减小l = mid(二分搜索区间选小的)
}

// 找最大值最小，一看就是二分搜索答案
// 比Kruskal快
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);

    double l = 0, r = 10000;  // 二分搜索答案log(V)，再暴力验证O(V^2)=O(E)
    // r-l<0.0001 表示与目标的误差小于0.0001时跳出循环 (二分搜索需要注意的地方1)
    while (r - l >= 0.0001)  // 不能改为 r-l>=0，因为需要的答案是2位精度的浮点数，所以二分查找知道r-l的差值<精度*0.01或者f(l)-f(r)的差值<精度*0.1。因为题目要求精确到2位，第三位会四舍五入
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
        cout << l << " " << r << endl;
    }
    printf("%0.2lf", l);  // 只能为l，因为当树正合适时返回值mid给的是l (二分搜索需要注意的地方2)
}
