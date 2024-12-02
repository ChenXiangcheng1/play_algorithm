#include <bits/stdc++.h>

using namespace std;

int n,m;
int a1[10000];
int v[10010];  // 反集树，敌人数组，记录一个敌人节点就好。在处理敌人的敌人就是朋友时，都是找父节点合并

int find(int x){
    if(x!=a1[x]) a1[x] = find(a1[x]);
    return a1[x];
}
void unionn(int x, int y){
    x = find(x);  y = find(y);
    if(x!=y)  a1[y] = x;
}

int main()
{
    int f,a,b;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        a1[i] = i;
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &f, &a, &b);
        if(f==0)  unionn(a, b);
        else{
            if(v[a] == 0)  v[a] = b;
            if(v[b] == 0)  v[b] = a;
            unionn(v[a], b);
            unionn(v[b], a);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(find(i)==i) ans++;
    }
    cout << ans << endl;
    return 0;
}
