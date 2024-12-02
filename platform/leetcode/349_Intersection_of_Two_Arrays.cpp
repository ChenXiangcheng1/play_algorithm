#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // set<int> record;
        // for (size_t i = 0; i < nums1.size(); i++) {
        //     record.insert(nums1[i]);
        // }
        // O(nlogn)
        set<int> record(nums1.begin(), nums1.end());
        set<int> resultSet;
        // O(nlogn)
        for (size_t i = 0; i < nums2.size(); i++) {
            if (record.find(nums2[i]) != record.end()) {
                resultSet.insert(nums2[i]);
            }
        }
        // vector<int> resultVector;
        // for (set<int>::iterator it = resultSet.begin(); it != resultSet.end(); it++) {
        //     resultVector.push_back(*it);
        // }
        // return resultVector;
        // O(n)
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
