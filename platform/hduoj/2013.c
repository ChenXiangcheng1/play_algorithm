#include <stdio.h>

int main(){
    int i;
    int n,res;
    while(scanf("%d",&n)==1){
        res=1;
        for(i=0;i<n-1;i++){
            res=2*(res+1);
        }
        printf("%d\n",res);
    }    
    return 0;
}
