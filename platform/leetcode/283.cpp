#include <iostream>
#include <vector>

using namespace std;

/**
 * 如果边从前向后遍历，边在原来的对象中补0，会有多余的消耗。 
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {        
        for (vector<int>::iterator it = nums.end() - 1; it >= nums.begin(); it--) {
            if (*it == 0) { 
                it = nums.erase(it);  // 需要给it重新赋值，不然it会成为野指针
                nums.push_back(0);
            }
        }
    }
};

int main()
{
    int arr[] = {0, 3, 1, 0, 12};
    vector<int> ivec(arr, arr + 5);
    Solution *solution = new Solution();
    (*solution).moveZeroes(ivec);
    for (size_t i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << " ";
    }
    cout << endl;
    return 0;
}
