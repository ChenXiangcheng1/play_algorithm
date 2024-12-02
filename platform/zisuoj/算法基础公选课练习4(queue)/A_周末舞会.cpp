#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a, b, t;
    cin >> a >> b >> t;
    queue<int> q1, q2;
    for (int i = 1; i <= a; i++) {
        q1.push(i);
    }
    for (int i = 1; i <= b; i++) {
        q2.push(i);
    }
    while (t--) {
        int ans1 = q1.front();
        int ans2 = q2.front();
        cout << ans1 << " " << ans2 << endl;
        q1.pop();
        q2.pop();
        q1.push(ans1);
        q2.push(ans2);
    }
    return 0;
}
