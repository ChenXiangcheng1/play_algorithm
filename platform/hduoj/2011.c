#include <stdio.h>

int main(){
	int i;
	int t,n,symbol;
	double res;
	scanf("%d",&t);
	while(t--){
		res=0,symbol=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			res+=symbol*1.0/i;
			symbol*=-1;
		}
		printf("%.2lf\n",res);
	}
	return 0;
}
