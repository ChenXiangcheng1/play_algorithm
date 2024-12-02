#include <iostream>
#include <cstring>

using namespace std;

string key, word, ans;

int main()
{
    while (getline(cin, key)) {
        int keylen = key.size();
        ans.clear();
        getline(cin, word);
        for (size_t i = 0; i < word.size(); i++) {
            int t = word[i] + key[i%keylen] - '0';
            if (t % 123 != t) {
                ans.push_back(t % 123 + 32);  // 7 t116
            // } else if (t < 32) {
            //     ans.push_back(t + 32);
            } else {
                ans.push_back(t);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
