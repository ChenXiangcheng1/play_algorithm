#include <iostream>
#include <algorithm>

using namespace std;

/*
	kruskal求最小生成树
	逐边遍历
*/

struct Msg {
	int v, w, weight;

	bool operator<(const Msg o) const {
		return weight < o.weight;
	}
}edge[6000];  // 需要输入初始化所有的边

const int MAXN = 1e6+100;
int parent[MAXN];
int find(long p) {
	if (p != parent[p])
		parent[p] = find(parent[p]);
	return parent[p];
}

int n, m;  // n表示节点的数量, m表示边的数量
void kruskal() {
	int cnt = 0;  // 最小生成树中边的数量
	long long sum = 0;  // 最小生成树的总权值
	for (long i = 0; i < m; i++) {
		int vRoot = find(edge[i].v);
		int wRoot = find(edge[i].w);
		if (vRoot != wRoot) {
			parent[wRoot] = vRoot;
			cnt++;
			sum += edge[i].weight;
			if (cnt >= n-1)
				break;  // 函数出口遍历完所有的边，或者最小生成树中边有n-1条了
		}
	}
	// 所有边顶点合并完后，只有一个并查集
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		parent[i] = i;
	sort(edge, edge+m);
	kruskal();
	return 0;
}

