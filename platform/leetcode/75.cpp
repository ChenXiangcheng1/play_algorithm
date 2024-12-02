#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // 计数排序 时间复杂度O(1), 空间复杂度O(k)（k=3）= O(1)
    void sortColorsA(vector<int>& nums) {
        int count[3] = {0};
        for (size_t i = 0; i < nums.size(); i++) {
            assert(nums[i] >= 0 && nums[i] < 3);
            count[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < count[i]; j++) {
                nums[index++] = i;
            }
        }
    }

    // 当颜色操作三个时，就无法使用三路快排优化了
    // Quick Sort 3 Ways 三路快排partition思路的应用 时间复杂度O(1)空间复杂度O(1)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = - 1;  // 索引表示 nums[1...zero] = 1
        int two = n;  // 索引表示 nums[two...n-1] = 2
        for (int i = 0; i < two; ) {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2) {
                swap(nums[--two], nums[i]);  // 因为索引two之前的元素不可以确定所以还需要判断i
            } else {  // nums[i] == 0
                assert(nums[i] == 0);
                swap(nums[i++], nums[++zero]);  // 因为索引zero后面的元素可以确定所以i++
            }
        }
    }
};

int main()
{
    vector<int> ivec = {2,2,2,3,3,3};
    Solution().sortColors(ivec);
    return 0;
}
