#include <iostream>
// #include <algorithm>,11之前的版本，swap在algorithm包中
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

// 模板函数 泛型
template<typename T>
void selectionSort(T arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);  // c++11,swap在std中
    }
}

int main(){
    // 整形数组排序测试
    int n=10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("Selection Sort",selectionSort,arr,n);
    // SortTestHelper::printArray(arr,n);
    delete[] arr;

    // 浮点数排序测试
    float b[4]={4.4,3.3,2.2,1.1};
    SortTestHelper::testSort("Selection Sort",selectionSort,b,4);
    SortTestHelper::printArray(b,4);

    // 字符串数组排序测试
    string c[4]={"D","C","B","A"};
    SortTestHelper::testSort("Selection Sort",selectionSort,c,4);
    SortTestHelper::printArray(c,4);

    // 结构体数组排序测试
    Student d[4]={{"D",90},{"C",100},{"B",95},{"A",95}};
    SortTestHelper::testSort("Selection Sort",selectionSort,d,4);
    SortTestHelper::printArray(d,4);
    return 0;
}
