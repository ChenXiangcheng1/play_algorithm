#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

// 这题在OJ上写过

class Solution {
public:
    // 暴力 O(n^2)

    // 二分搜索优化 O(nlogn)
    vector<int> twoSumA(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int l = i+1, r = numbers.size()-1;  // 在[i+1, n]中搜索
            while (l <= r) {
                int mid = l + (r-l)/2;
                if (numbers[mid] == target-numbers[i]) {  // 如果mid == i的情况需要跳过
                    return {i+1, mid+1};  // 返回vector可以采用{}的方式
                } else if (numbers[mid] < target-numbers[i]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return {-1, -1};
    }

    // 对撞指针O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        assert(numbers.size() >= 2);
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l+1, r+1};
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
                r--;
            }
        }
        throw invalid_argument("The input no solution.");
    }

    // map哈希表查询 O(n)
    vector<int> twoSumB(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++) {
            if (map.find(target - numbers[i]) != map.end()) {
                return {map[target-numbers[i]], i+1};
            }
            map[numbers[i]] = i+1;
        }
        throw invalid_argument("The input no solution.");
    }
};

int main()
{
    vector<int> ivec = {2, 7, 11, 25};
    vector<int> vec = Solution().twoSum(ivec, 9);
    cout << vec[0] << vec[1] << endl;
    return 0;
}
