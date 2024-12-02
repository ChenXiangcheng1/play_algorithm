#include <stdio.h>

int pow(int n,int m){
	int i;
	int ret=1;
	for(i=0;i<m;i++){
		ret*=n;
	} 
	return ret;
}

int main(){
	int i;
	int m,n,flag;
	while(scanf("%d%d",&m,&n)==2){
		flag=0;
		for(i=m;i<=n;i++){
			if(i==pow(i/100,3)+pow(i/10%10,3)+pow(i%10,3)){
				if(!flag){
					printf("%d",i);	
				}else{
					printf(" %d",i);
				}
				flag=1;
			}
		}
		if(!flag){
			printf("no");
		}
		printf("\n");                                         
	}	                                               
	return 0;
}
