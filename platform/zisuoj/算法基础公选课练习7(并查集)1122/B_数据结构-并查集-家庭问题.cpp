#include <iostream>

using namespace std;

int parent[105], rankN[105], sz[105];

// O(h)
int find(int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

// O(h)
void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if (pRoot == qRoot)
        return;
    if (rankN[pRoot] < rankN[qRoot]) {
        parent[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    }
    else if (rankN[pRoot] > rankN[qRoot]) {
        parent[qRoot] = pRoot;
        sz[pRoot] += sz[qRoot];
    }
    else {
        parent[qRoot] = pRoot;
        rankN[pRoot]++;
        sz[pRoot] += sz[qRoot];
    }
}

int set_size(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i)
            ret++;
    }
    return ret;
}

int max_size(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret = max(ret, sz[i]);
    return ret;
}

int main()
{
    int n, k, a, b, ans1, ans2;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankN[i] = 1;
        sz[i] = 1;
    }
    while (k--) {
        cin >> a >> b;
        unionElements(a, b);
    }
    ans1 = set_size(n);
    ans2 = max_size(n);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
