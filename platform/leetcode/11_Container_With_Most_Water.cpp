#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        assert(height.size() >= 2);

        int l = 0, r = height.size() - 1;
        int area = 0;
        while(l < r){
            area = max(area , min(height[l], height[r]) * (r - l));  // 计算容量，短板才是需要需要移动的
            if(height[l] < height[r])
                l ++;
            else
                r --;
        }
        return area;
    }
};
