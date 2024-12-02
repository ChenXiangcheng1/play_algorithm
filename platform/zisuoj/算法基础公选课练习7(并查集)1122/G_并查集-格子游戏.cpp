#include <iostream>

using namespace std;

// N=40000 所需时间复杂度O(n*sqrt(n))

// 并查集，不是合并后如何判断是否有环，而是合并前已经在同一个集合中了说明有环

int parent[40100];

int find(int p) {
    while (p != parent[p]) {
        parent[p] = find(parent[p]);
        p = parent[p];
    }
    return parent[p];
}

int main()
{
    char ch;
    int C, m, x, y, p, q, pRoot, qRoot;
    cin >> C >> m;
    for (int i = 0; i < C*C; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> ch;
        p = (x-1)*C+(y-1);
        if (ch == 'D')
            q = p + C;
        else
            q = p + 1;
        pRoot = find(p);
        qRoot = find(q);
        if (pRoot != qRoot)
            parent[qRoot] = pRoot;
        else {
            cout << i << endl;
            return 0;
        }
    }
    cout << "draw" << endl;
    return 0;
}
