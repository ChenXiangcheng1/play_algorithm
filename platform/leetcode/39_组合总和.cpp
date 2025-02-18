#include <iostream>
#include <vector>

using namespace std;

/// Backtrack
/// Time Complexity: O(n^n)
/// Space Complexity: O(target)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur_res;
        solve(candidates, 0, target, cur_res, res);
        return res;
    }

private:
    void solve(const vector<int> &candidates, int index, int target,
                vector<int>& cur_res, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(cur_res);
            return;
        }

        for(int i = index ; i < candidates.size() ; i ++)
            if(target >= candidates[i]){
                cur_res.push_back(candidates[i]);
                solve(candidates, i, target - candidates[i], cur_res, res);
                cur_res.pop_back();
            }

        return;
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> res = Solution().combinationSum(candidates, 7);
    for(const vector<int>& a_res: res)
        print_vec(a_res);

    return 0;
}