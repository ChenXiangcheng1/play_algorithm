#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for ( int i = triangle.size()-2 ; i >= 0 ; i--  ) {  // 从大到小迭代，要使用int不能使用size_t，因为size_t是无符号数0-1会变得很大
            for ( size_t j = 0 ; j < triangle[i].size() ; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);  // 状态转移方程，ij表示状态，和表示价值
            }
            // triangle.pop_back();
        }
        return triangle[0][0];
    }
};

int main()
{
    vector<vector<int>> ivec = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout<<Solution().minimumTotal(ivec)<<endl;
    return 0;
}
