#include <stdio.h>
#include <Math.h>

int main(){
	int i;
	double n,m,res;
	while(scanf("%lf%lf",&n,&m)==2){
		res=0;
		for(i=0;i<m;i++){
			res+=n;
			n=sqrt(n);
		}
		printf("%.2lf\n",res);
	}	
	return 0;
}
