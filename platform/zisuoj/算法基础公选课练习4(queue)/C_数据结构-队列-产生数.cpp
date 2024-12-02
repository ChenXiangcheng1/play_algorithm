#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int n, k;
unordered_map<int, vector<int> > transform;  // 使用hashmap查找更好
int f[10000];

int dfs() {
    queue<int> q;
    int tot = 0;
    q.push(n);
    f[n] = 1;
    tot++;
    while (!q.empty()) {
        // 难点是如何进行状态转移，显然应该遍历n的每一位找转换
        int cur = q.front();
        int wei = 1;
        while (cur) {
            int tmp = cur % 10;
            if (transform.find(tmp) != transform.end()) {
                for (size_t i = 0; i < transform[tmp].size(); i++){
                    int p = q.front() + (transform[tmp][i]-tmp)*wei;
                    if (!f[p]) {
                        q.push(p);                        
                        f[p] = 1;
                        tot++;
                    }
                }
            }
            cur /= 10;
            wei *= 10;
        }
        q.pop();
    }
    return tot;
}

int main() 
{
    cin >> n >> k;
    for (int key, value, i = 0; i < k; i++) {
        cin >> key >> value;
        transform[key].push_back(value);
    }
    cout << dfs() << endl;
    return 0;
}
