#include <iostream>
#include <map>

using namespace std;

map<string, string> parent;

string find(string p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

void unionElements(string p, string q) {
    string pRoot = find(p);
    string qRoot = find(q);
    if (pRoot == qRoot)
        return;
    // 不能使用rank size优化，因为根节点需要是固定的
    parent[qRoot] = pRoot;
}

int main()
{
    char op;
    string strA, strB, strC;
    while (cin >> op && op != '$') {
        switch (op) {
            case '#':
                cin >> strA;
                if (parent.find(strA) == parent.end())
                    parent[strA] = strA;
                break;
            case '+':
                cin >> strB;
                if (parent.find(strB) == parent.end())
                    parent[strB] = strB;
                unionElements(strA, strB);
                break;
            case '?':
                cin >> strC;
                cout << strC << " " << find(strC) << endl;
                break;
        }
    }

    // 写完这题，可以试试昨天的题目可以不可以使用并查集。答案是不可以，因为这题关系不会形成环，而昨天的题目关系会形成环。
    return 0;
}
