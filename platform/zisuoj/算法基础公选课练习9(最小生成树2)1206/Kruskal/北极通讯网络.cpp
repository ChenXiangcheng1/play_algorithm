#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 北极通讯网络
/*
	需要分配卫星设备的同时使剩下的顶点的边的最大权值最小，即最小生成树中权值大的边顶点分配卫星设备
	不可以使用prime算法，因为prime求出最小生成树后再排序分配卫星设备不能保证最小生成树的第n-k条边的权值最小
	prime算法是逐点遍历O(V*log(E))
	kruskal算法是逐边遍历O(E*log(E)+E)，如果对边的权值有要求应该使用kruskal算法
*/

struct edge {
	int u, v;
	double dis;
}e[130000];  // 边数组

int n, k, num, f[510], ans;  // f表示顶点并查集，num表示边数 ans
double x[510], y[510];

bool cmp(edge x, edge y) {
	return x.dis < y.dis;
}

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void kruskal() {
	int x1, y1, mst = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	sort(e+1, e+1+num, cmp);
	for (int i = 1; mst < n-1 && i <= num; i++) {
		x1 = find(e[i].u);
		y1 = find(e[i].v);
		if (x1 != y1) {
			f[x1] = y1;
			mst++;
			if (mst >= n-k) {
				printf("%.2lf\n", e[i].dis);
				return;
			}
		}
	}
	return;
}

int main() {
	cin >> n >> k;
	if (n == k) {
		cout << "0.00" << endl;
		return 0;
	}
	//  计算边，需要O(n^2)的时间复杂度
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		for (int j = 1; j < i; j++) {
			e[++num].u = j;
			e[num].v = i;
			e[num].dis = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		}
	}
	kruskal();
}
