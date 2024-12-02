#include <bits/stdc++.h>

using namespace std;

// 先排序再找第K大的元素: O(nlogn)
// 快排思路 利用快排partition中,将pivot放置在了其正确的位置上的性质 起始就是快排: O(n)

class Solution {
private:
    int partition( vector<int>& nums, int l, int r ){
        // 随机元素作为主元，放置到第一个位置
        int p = rand()%(r-l+1) + l;
        swap( nums[l] , nums[p] );
        // 维护这种状态 [l+1: lt) > p; [lt: i) < p
        int lt = l + 1;
        for( int i = l + 1 ; i <= r ; i ++ )
            if( nums[i] > nums[l] )
                swap(nums[i], nums[lt++]);
        // 把主元放置到他应该在的位置
        swap(nums[l], nums[lt-1]);
        return lt-1;
    }

    // 私有递归函数, 对arr[l:r]部分进行快速排序
    int findKthLargest(vector<int>& nums, int l, int r, int k){
        if ( l == r )
            return nums[l];

        int p = partition(nums, l, r);

        if ( p == k )
            return nums[p];
        else if ( k < p )
            return findKthLargest(nums, l, p-1, k);
        else // k > p
            return findKthLargest(nums, p+1 , r, k);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        return findKthLargest(nums, 0, nums.size()-1 , k - 1 );  // 寻找索引为k-1的元素
    }
};
