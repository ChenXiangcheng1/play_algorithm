#include <iostream>
#include <vector>

using namespace std;

// 双指针，边界

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t k = 0;  // 维护nums[0, k)为非0元素
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[k++] = nums[i];
            }
        }
        for (size_t i = k; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main()
{
    int arr[] = {0, 3, 1, 0, 12};
    vector<int> ivec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().moveZeroes(ivec);
    for (size_t i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << " ";
    }
    cout << endl;
    return 0;
}
