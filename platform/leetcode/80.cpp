#include <iostream>
#include <vector>

using namespace std;

// LeetCode80: 双指针解决方案

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 原地算法，没有额外空间
        if (nums.size() <= 2) {
            return nums.size();
        }
        int k = 2;  // 逻辑数组长度指针，即[0,k)是有效数组
        for (size_t i = 2; i < nums.size(); i++) {  // 遍历指针
            if (nums[i] != nums[k - 1] || (nums[i] == nums[k - 1] && nums[i] != nums[k - 2])) {  // 需要注意k-1才是前一个元素
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

int main()
{

    return 0;
}
