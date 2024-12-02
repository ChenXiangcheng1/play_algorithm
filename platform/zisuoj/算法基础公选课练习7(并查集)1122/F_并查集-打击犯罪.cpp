#include <iostream>
#include <vector>

using namespace std;

// 删除顶点后，计算每个联通分量的大小<n/2，时间复杂度O(v^2)。使用并查集O(v)，因为合并是O(1)复杂度而计算连通分量是O(v)。并查集面对集合添加操作真的优化很大
// 这题是需要size和并查集有联系，但是这是邻接表如何建立并查集呢(这题关键)?依题意遍历，从n~1遍历所有点及其有效(>i)邻点建立并查集

vector<int> adj[1005];  // 邻接表
int n;
int parent[1005], sz[1005];

int find(int p) {
    while (p != parent[p]) {
        parent[p] = find(parent[p]);
        p = parent[p];
    }
    return parent[p];
}

void solve() {
    for (int i = n; i >= 1; i--) {  // 从1~n打击犯罪集团(需重现建立并查集)，即从i:n~1枚举[i,n]犯罪集团(一直合并操作)
        for (size_t j = 0; j < adj[i].size(); j++) {
            // 当前节点i 子节点adj[i][j]
            if (adj[i][j] > i) {  // 遍历邻点建立并查集，因为i之前都是被打击掉的，不能被遍历到
                int pRoot = find(i);
                int qRoot = find(adj[i][j]);
                if (pRoot != qRoot) {
                    parent[qRoot] = pRoot;
                    sz[pRoot] += sz[qRoot];
                    if (sz[pRoot] > n/2) {
                        cout << i << endl;
                        return;
                    }
                }
            }
        }
    }
    return;
}

int main()
{
    int m, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> k;
            adj[i].push_back(k);
        }
        parent[i] = i;
        sz[i] = 1;
    }
    solve();
    return 0;
}
