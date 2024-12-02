#include <stdio.h>
#include <algorithm>

/*
void sort(int arr[],int n){
    
}
*/

int cmp(int a,int b){
	return abs(a)>abs(b);  //  abs函数在stdlib头文件中 
}

int main(){
    int n;
    int arr[110];
    while(scanf("%d",&n)==1&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        std::sort(arr,arr+n,cmp);  // less()参数 
        for(int i=0;i<n-1;i++){
            printf("%d ",arr[i]);
        }
        printf("%d\n",arr[n-1]);
    }
    return 0;
}
