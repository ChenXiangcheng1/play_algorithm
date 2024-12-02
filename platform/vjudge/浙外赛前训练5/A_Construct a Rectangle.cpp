#include <iostream>

using namespace std;

int main()
{
    int t, l1, l2, l3;
    cin >> t;
    while (t--) {
        cin >> l1 >> l2 >> l3;
        if (l1 == l2)
            cout << (l3 % 2 ? "NO" : "YES") << endl;
        else if (l1 == l3)
            cout << (l2 % 2 ? "NO" : "YES") << endl;
        else if (l2 == l3)
            cout << (l1 % 2 ? "NO" : "YES") << endl;
        else if (l1 == l2+l3 || l2 == l1+l3 || l3 == l1+l2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
