#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度O(n^n)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if (nums.size() == 0)
            return res;

        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

    // p中保存了一个有index个元素的排列
    // 向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                // 将nums[i]添加在p中
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index+1, p);
                // 搜索空间的元素之间互相是冲突的所以需要将状态回溯
                p.pop_back();
                used[i] = false;
            }
        }
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3};
    vector<vector<int>> res = Solution().permute(ivec);
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
