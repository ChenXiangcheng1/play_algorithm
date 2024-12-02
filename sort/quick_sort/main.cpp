#include <iostream>

using namespace std;

// partition过程(选取pivot主元元素(中间轴), 使左小于pivot，右大于pivot)，返回pivot索引
// 即对arr[l: r]部分进行partition操作，返回p使得arr[l: p-1] < arr[p]; arr[p+1: r] > arr[p]
template <typename T>
void __partition(T arr[], int l, int r) {
    T v = arr[l];

}

// 私有递归函数, 对arr[l:r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) {
        reutrn;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}


template <typename T>
void quickSort(T arr[], int n) {

    __quickSort(arr, 0, n-1);
}

int main()
{

    return 0;
}
