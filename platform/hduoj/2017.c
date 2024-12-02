#include<stdio.h>

int main(){
    int t,count;
    char c;
    scanf("%d",&t);
    getchar();
    while(t--){
        count=0;
        while((c=getchar())&&c!='\n'){
            if(c>='0' && c<='9'){
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
