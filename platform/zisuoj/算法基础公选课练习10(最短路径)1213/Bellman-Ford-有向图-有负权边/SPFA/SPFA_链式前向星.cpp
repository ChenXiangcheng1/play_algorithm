#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int M = 10000;
struct sy {
    long t, w, next;
}edge[M];
int head[100];

bool v[100];
int dist[100], q[10000];

void spfa() {
    memset(v, 0, sizeof(v));
    memset(dist, 127, sizeof(dist));
    long l = 0, r = 0;
    q[r++] = 1;  // 入队起始顶点1
    v[1] = true;  // 表示是否在队中
    dist[1] = 0;  // 起始顶点到自身的代价为0
    while (l < r) {
        long x = q[l++];  // 出队
        v[x] = false;
        for (long i = head[x]; i != 0; i= edge[i].next) {
            long t = edge[i].t;
            if (dist[x] + edge[i].w < dist[t]) {
                dist[t] = dist[x] + edge[i].w;
                if (!v[t]) {
                    q[r++] = t;
                    v[t] = true;
                    // 可以添加对每个顶点入队次数的统计来判断是否有负权环
                }
            }
        }
    }
}


int main()
{

    return 0;
}
