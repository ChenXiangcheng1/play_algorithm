#include <stdio.h>

int main(){
	int t,n,res;
	while(scanf("%d",&t)==1){
		res=1;
		while(t--){
			scanf("%d",&n);
			if(n&1)
				res*=n;
		}
		printf("%d\n",res);
	}	
	return 0;
} 
