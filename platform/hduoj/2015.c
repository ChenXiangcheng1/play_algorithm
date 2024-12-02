#include <stdio.h>

int main(){
    int n,m,res,curnum,flag;
    while(scanf("%d%d",&n,&m)==2){
        // 先想想等不等化为数学问题
        res=0,curnum=2,flag=0;
        for(int i=1;i<=n;i++){
            res+=curnum;
            if(i%m==0){
                // 这里好丑啊，想想能怎么优化
                if(!flag){
                    printf("%d",res/m);
                }else{
                    printf(" %d",res/m);
                }
                flag=1;
                res=0;
            }
            curnum+=2;
        }
        if(res!=0){
            if(!flag){
                printf("%d",res/(n%m));
            }else{
                printf(" %d",res/(n%m));
            }
            flag=1;
        }
        printf("\n");
    }
    return 0;
}
