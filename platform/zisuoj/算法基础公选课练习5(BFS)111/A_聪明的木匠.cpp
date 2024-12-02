#include <iostream>
#include <queue>

using namespace std;

/**
 * 木匠 求最少的花费？
 * 实质：哈夫曼树(最优二叉树)
 *
 * 正向思维的解决方案太难想了：分成n段，需要n-1次分割，那么每次怎么分？？
 * 逆向思维：有n段，需要n-1次合并，若每次合并都是最少花费那么n段合并就是最少花费
 */

int main()
{
    int n, sum = 0, qtop1, qtop2;
    priority_queue<int, vector<int>, greater<int> > que;
    cin >> n;
    for (int l, i = 0; i < n; i++) {
        cin >> l;
        que.push(l);
    }

    while (!que.empty() && que.size() >= 2) {
    // for (int i = 0; i < n - 1; i++) {
        qtop1 = que.top();
        que.pop();
        qtop2 = que.top();
        que.pop();
        sum += qtop1 + qtop2;
        que.push(qtop1 + qtop2);
    }
    cout << sum << endl;
    return 0;
}
