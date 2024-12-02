#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> dvec;
vector<string> fvec;

int main()
{
    string str, type;
    while (getline(cin, str, ' ') && getline(cin, type)) {
        if (type == "Dir") {
            dvec.push_back(str);
        } else if (type == "File") {
            fvec.push_back(str);
        }
    }
    sort(dvec.begin(), dvec.end());
    sort(fvec.begin(), fvec.end());
    for (vector<string>::iterator it = dvec.begin(); it < dvec.end(); it++) {
        cout << *it << " Dir" << endl;
    }
    for (vector<string>::iterator it = fvec.begin(); it < fvec.end(); it++) {
        cout << *it << " File" << endl;
    }
    return 0;
}
