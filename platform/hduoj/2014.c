#include <stdio.h>

int main(){
    int i;
    int n;
    double highest,lowest,res,score;
    while(scanf("%d",&n)==1){
        highest=-1;
        lowest=110;
        res=0;
        for(i=0;i<n;i++){
            scanf("%lf",&score);
            if(score>highest){
                highest=score;
            }
            if(score<lowest){
                lowest=score;
            }
            res+=score;
        }
        res-=highest;
        res-=lowest;
        printf("%.2lf\n",res/(n-2));
    }
    return 0;
}
