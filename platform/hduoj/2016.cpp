#include <stdio.h>
#include <vector>

using std::vector;

int main(){
    // 看看有没有不用STL的更好的方法
    int t,n,min;
    vector<int> vector;
    while(scanf("%d",&t)==1&&t){
        min=0,vector.clear();
        for(int i=0;i<t;i++){
            scanf("%d",&n);
            vector.push_back(n);
            if(n<vector[min]){
                min=i;
            }
        }
        printf("%d",vector[min]);
        for(int i=1;i<vector.size();i++){
            if(i==min){
                printf(" %d",vector[0]);
                continue;
            }
            printf(" %d",vector[i]);
        }
        printf("\n");
    }
    return 0;
}
