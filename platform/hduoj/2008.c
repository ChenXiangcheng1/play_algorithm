#include <stdio.h>

int main(){
	int t,negnum,zeronum,posnum;
	double n;
	while(scanf("%d",&t)==1&&t){
		negnum=zeronum=posnum=0;
		while(t--){
			scanf("%lf",&n);
			if(n<0){
				negnum++;
			}else if(n==0){
				zeronum++;
			}else{
				posnum++;
			}
		}
		printf("%d %d %d\n",negnum,zeronum,posnum);
	}	
	return 0;
}
