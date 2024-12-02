#include <iostream>

using namespace std;

// E=2e6, kruskal O(E)

const int maxn = 1e6+100;
int parent[maxn];

int find(int p) {
    return p==parent[p] ? p : parent[p]=find(parent[p]);
}

int main()
{
    int R, C, x1, x2, y1, y2, ans = 0;
    cin >> R >> C;
    for(int i = 0; i <= R*C-1; i++)
        parent[i] = i;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int p = (x1-1)*C+y1-1;
        int q = (x2-1)*C+y2-1;
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot != qRoot) {
            parent[qRoot] = pRoot;
        }
    }
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << parent[i*C+j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < R-1; i++) {  // 1000
        for (int j = 0; j < C; j++) {  // 1000
            int p = i*C+j;
            int pRoot = find(p);
            int qRoot = find(p+C);
            if (pRoot != qRoot) {
                parent[qRoot] = pRoot;
                ans+=1;
            }
        }
    }
    // cout << "ans: " << ans << endl;
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << parent[i*C+j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C-1; j++) {
            int p = i*C+j;
            int pRoot = find(p);
            int qRoot = find(p+1);
            if (pRoot != qRoot) {
                parent[qRoot] = pRoot;
                ans+=2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
