#include <stdio.h>

int main(){
    int y;
    int cows[4];
    while(scanf("%d",&y)==1&&y){
        cows[0]=1,cows[1]=0,cows[2]=0,cows[3]=0;
        y--;
        while(y--){
            cows[0]+=cows[3];
            cows[3]=cows[2];
            cows[2]=cows[1];
            cows[1]=cows[0];
        }
        printf("%d\n",cows[0]+cows[1]+cows[2]+cows[3]);
    }
    return 0;
}
