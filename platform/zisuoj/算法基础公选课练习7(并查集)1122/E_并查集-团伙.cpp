#include <iostream>

using namespace std;

// 反集(敌人的敌人是朋友)
/**
 * 思路：并查集对于每个点i(小树)，再开点i+n(小树)，储存敌对关系。要开两倍空间
 * 朋友关系合并时，实点树合并实点树；敌人关系合并时，实点树合并虚点的实点树(即合并了敌人的敌人)
 * 实点上即存储朋友关系，又存储敌人关系，以节点虚实区分
 */

int parent[2005], n;

int find(int p) {
    if (p != parent[p])
        parent[p] = find(parent[p]);
    return parent[p];
}

void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot)
        return;
    parent[qRoot] = pRoot;
}

int getSize() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (i == parent[i]) {
            ret++;
        }
    }
    return ret;
}

int main()
{
    int m, p, x, y, ans;
    cin >> n >> m;
    for (int i = 1; i <= 2*n; i++)  // 集合[1+n,2*n]是虚节点，用于表示反集。集合树上实节点表示朋友关系，虚节点表示敌人关系
        parent[i] = i;
    while (m--) {  // 100,000
        cin >> p >> x >> y;
        switch (p) {
            case 0:
                unionElements(x, y);
                break;
            case 1:
                unionElements(y, x+n);  // 把虚节点x+n的根节点接给y，表示把x+n的敌人的朋友都给y了(x和y是敌人)，即x的敌人的敌人就是x的朋友
                unionElements(x, y+n);
                break;
        }
    }
    ans = getSize();
    cout << ans << endl;
    return 0;
}
