#include <stdio.h>

int main(){
	int i,j;
	int x,y,n;
	while(scanf("%d%d",&x,&y)==2&&(x||y)){
		for(i=x;i<=y;i++){
			n=i*i+i+41;
			for(j=2;j*j<=n;j++){
				if(n%j==0){
					break;
				}
			}
			if(j*j<=n){
				break;	
			}
		}
		if(i>y){
			printf("OK\n");
		}else{
			printf("Sorry\n");
		}
	}
	return 0;
}
