#include <iostream>
#include <vector>

using namespace std;

// 使用辅助空间的思路

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeroElements;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nonZeroElements.push_back(nums[i]);
            }
        }
        for (size_t i = 0; i < nonZeroElements.size(); i++) {
            nums[i] = nonZeroElements[i];
        }
        for (size_t i = nonZeroElements.size(); i < nums.size(); i++) {
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
