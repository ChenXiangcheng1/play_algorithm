#ifndef SORT_SORTTESTHELPER_H
#define SORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{

    // 生成有n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL<=rangeR);
         int *arr = new int[n];
        srand(time(NULL));
        for(int i=0;i<n;i++){
            arr[i]=rand()%(rangeR - rangeL + 1)+rangeL;  // 需要加1，因为需要[0,2]=需要(0,3)
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // 测试排序结果(升序)的正确性
    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i=0;i<n-1;i++){
            if(arr[i+1]<arr[i]){
                return false;
            }
        }
        return true;
    }

    // 测试算法的性能
    template<typename T>
    void testSort(string sortName, void(*sort)(T[],int),T arr[],int n){  // 函数指针 返回值(函数指针名)(参数类型) 
        clock_t startTime=clock();
        sort(arr,n);
        clock_t endTime=clock();
        assert(isSorted(arr,n));
        cout<<sortName<<" : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
}

#endif  // SORT_SORTTESTHELPER_H