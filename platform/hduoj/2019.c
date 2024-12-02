#include <stdio.h>

int main(){
    int n,m,l,mflag;
    while(scanf("%d%d",&n,&m)==2&&(n||m)){
        mflag=0;
        while(n--){
            scanf("%d",&l);
            if(m<l&&mflag==0){
                printf("%d ",m);
                mflag=1;
            }
            if(n==0){
                printf("%d",l);
            }else{
                printf("%d ",l);
            }
        }
        if(mflag==0){
            printf("%d",m);
        }
        printf("\n");
    }
    return 0;
}
