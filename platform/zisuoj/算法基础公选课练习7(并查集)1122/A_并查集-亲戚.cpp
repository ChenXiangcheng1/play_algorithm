#include <iostream>

#define MAXN 20005

using namespace std;

/**
 * **维护集合编号**的数据结构，只有一个修改操作就是合并
 */

int parent[MAXN];  // 森林数组

int rankN[MAXN];  // 给树根的权重，反应树的相对深度大小的关系

// O(h)，返回p元素所属的集合编号
int find(int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];  // 路径压缩：从叶子到根节点，只要p指针没迭代到根节点就把p接给父父节点下，减去了一层，总体方法减去了high/2层 // 表示若p节点不等于父节点，则说明p不是根节点，就把p接给上上个节点下
        p = parent[p];  // p指针移到当前节点的上个节点
    }
    return p;

    // if (p != parent[p])
    //     parent[p] = find(parent[p]);
    // return parent[p];
}

// O(h)
void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot)  // 只有不在同一个集合时才需要合并。没有这一步，树可能会断开。
        return;

    if (rankN[pRoot] < rankN[qRoot]) {
        parent[pRoot] = qRoot;
    } else if (rankN[pRoot] > rankN[qRoot]) {
        parent[qRoot] = pRoot;
    } else {
        parent[qRoot] = pRoot;
        rankN[pRoot]++;
    }
}

bool isConnected(int p, int q) {
    return find(p) == find(q);
}

int main()
{
    // std::ios::sync_with_stdio(false);  // 没什么用
    // std::cin.tie(0);
    // cout.tie(0);
    int n, m, a, b;
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankN[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        // scanf("%d%d", &a, &b);
        cin >> a >> b;
        unionElements(a, b);
    }
    scanf("%d", &m);
    // cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (isConnected(a, b))
            printf("Yes\n");  // 1,000,000次，大输出还是用printf吧，cout会超时
            // cout << "Yes" << endl;
        else
            printf("No\n");
            // cout << "No" << endl;
    }
    return 0;
}
