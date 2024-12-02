#include <iostream>
#include "MyUtil.h"

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
    int l = 0, r = n;  // 维护循环不语义变量(代替递归)，在arr[l, r)中寻找target
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return -1;
}

int main()
{
    int n = 1e6;
    int *data = Array_MYUTIL_H::generateOrderedArray(n);
    clock_t startTime = clock();
    for (int i = 0; i < n; i++) {
        assert(i == binarySearch(data, n, i));
    }
    clock_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
