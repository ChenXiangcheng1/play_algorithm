#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 返回不重复的全排列，和校赛的一题一样

/// Most Naive Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        if(nums.size() == 0)
            return res;
        used = vector<bool>(nums.size(), false);
        // 排序
        sort(nums.begin(), nums.end());

        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }

private:
    void generatePermutation(const vector<int>& nums, int index, vector<int> &p){
        // 递归终止条件
        if(index == nums.size()){
            res.push_back(p);
            return;
        }

        // 调用递归
        for(int i = 0 ; i < nums.size() ; i ++) {
            if(!used[i]){
                // 如果nums[i]和前一个元素nums[i-1]相等，则当nums[i-1]被使用了才能使用nums[i] (因为相同元素优先使用前面的，前面的没使用说明已经使用过了，则同元素都不使用)
                if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                    continue;
                p.push_back(nums[i]);
                used[i] = true;

                generatePermutation(nums, index + 1, p);

                p.pop_back();
                used[i] = false;
            }
        }
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = Solution().permuteUnique(nums1);
    for(const vector<int>& tres: res1)
        printVec(tres);

    vector<int> nums2 = {2, 2, 1, 1};
    vector<vector<int>> res2 = Solution().permuteUnique(nums2);
    for(const vector<int>& tres: res2)
        printVec(tres);

    return 0;
}