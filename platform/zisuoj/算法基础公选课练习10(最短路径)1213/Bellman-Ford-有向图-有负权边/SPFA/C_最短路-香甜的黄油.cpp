#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// 看问题是所有点对的问题，但是Floyed的V^3的时间复杂度只能处理到N=300
// 可以用 Shortest Path Fast Algorithm
/**
 * SPFA是Bellman-Ford的改进
 *
 * Dijkstra是贪心选找最短路节点，遍历点O(V)找最短路O(V) = O(V*V)
 * Bellman-Ford是v-1轮松弛操作，V-1次松弛O(V)，对所有边O(E) = O(V*E)
 * SPFA是可松弛的循环松弛, K次松弛 = O(kE)
 */

int head[805];  // head[i]表示从顶点i出发的第一条边在edge[]中的位置

// 链式前向星
struct E {
    int t, w, next;  // t是目标顶点，w权值，next下一条边
}edge[2910];  // 因为是无向图，所以开边数组要开double！！！找了半天

int k = -1;
// 添加边 s->t 权值为w
void add_edge(int s, int t, int w) {  // k是边的编号
    edge[++k].t=t;
    edge[k].w=w;
	edge[k].next = head[s];
    head[s] = k;
}

int N, P, C;
int cnt[805];

bool isInQue[805];  // 表示牧场是否在队列中
int dist[805];
queue<int> que;

void SPFA(int s) {
    memset(isInQue, 0, sizeof(isInQue));
    memset(dist, 127, sizeof(dist));  // 0x7f7f7f7f
    que.push(s);
    isInQue[s] = true;
    dist[s] = 0;  // 可以居然忘记了，不设置起始的最短路算法开始不了
    while (!que.empty()) {  // 可松弛的循环松弛
        int cur = que.front();  que.pop();
        isInQue[cur] = false;

        for (int i = head[cur]; i != -1; i = edge[i].next) {
            int nextN = edge[i].t;
            if (dist[cur] != 0x7f7f7f7f && dist[cur] + edge[i].w < dist[nextN]) {
                dist[nextN] = dist[cur] + edge[i].w;
                if (!isInQue[nextN]) {
                    que.push(nextN);
                    isInQue[nextN] = true;
                }
            }
        }
    }
}

int main()
{
    // freopen("C.in", "r", stdin);
    // freopen("P1828_2.in", "r", stdin);
    // freopen("C_out.out", "w", stdout);
    cin >> N >> P >> C;  // 奶牛数[0,N)  牧场数[1,P]  牧场道路数[0,C)
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    memset(head, -1, sizeof(head));
    for (int i = 0; i < C; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        add_edge(s, t, w);
        add_edge(t, s, w);
    }

    ll sum[805] = {0};
    for (int i = 1; i <= P; i++) {
        if (cnt[i] <= 0)
            continue;
        SPFA(i);
        for (int j = 1; j <= P; j++) {
            if (sum[j] == -1 || dist[j] == 0x7f7f7f7f) {
                sum[j] = -1;
            } else {
                sum[j] += cnt[i] * dist[j];
            }
        }
    }

    int mind = 0x7f7f7f7f;
    for (int i = 1; i <= P; i++)
        if (sum[i] != -1 && sum[i] < mind)
            mind = sum[i];
    cout << mind << endl;
    return 0;
}
