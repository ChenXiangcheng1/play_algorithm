#include <iostream>
#include <vector>
using namespace std;

/// Recursive get all the permutations in place
/// Time Complexity: O(n!)
/// Space Complexity: O(n)
class Solution {

private:
    vector<vector<int>> res;

    void generatePermutation(vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = index ; i < nums.size() ; i ++){
            swap(nums[i], nums[index]);
            generatePermutation(nums, index + 1);
            swap(nums[i], nums[index]);
        }
        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.size() == 0)
            return res;
        generatePermutation(nums, 0);
        return res;
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
