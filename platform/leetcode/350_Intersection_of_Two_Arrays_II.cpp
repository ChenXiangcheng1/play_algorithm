#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> record;
        for (size_t i = 0; i < nums1.size(); i++) {
            // record[nums1[i]]++;
            if (record.find(nums1[i]) == record.end()) {
                record.insert(make_pair(nums1[i], 1));
            } else {
                record[nums1[i]]++;
            }
        }
        vector<int> resultVector;
        for (size_t i = 0; i < nums2.size(); i++) {
            if (record.find(nums2[i]) != record.end() && record[nums2[i]] > 0) {
                resultVector.push_back(nums2[i]);
                record[nums2[i]]--;
                if (record[nums2[i]] == 0) {
                    record.erase(nums2[i]);
                }
            }
        }
        return resultVector;
    }
};
