#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 双指针，交换

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t k = 0;  // 指向第一个0元素
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i]) {  // 非0时，k也需要++
                if (i != k) {
                    swap(nums[k++], nums[i]);
                } else {
                    k++;
                }
            }
        }
    }
};

int main()
{
    int arr[] = {1, 2, 0, 3, 12};
    vector<int> ivec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().moveZeroes(ivec);
    for (size_t i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << " ";
    }
    cout << endl;
    return 0;
}
