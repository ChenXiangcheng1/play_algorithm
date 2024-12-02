#include <stdio.h>

int main(){
	int t,sum;
	int salary;
	while(scanf("%d",&t)==1&&t){
		sum=0;
		while(t--){
			scanf("%d",&salary);
			if(salary>=100){
				sum+=salary/100;
				salary%=100;
			}
			if(salary>=50){
				sum+=salary/50;
				salary%=50;
			}
			if(salary>=10){
				sum+=salary/10;
				salary%=10;
			}
			if(salary>=5){
				sum+=salary/5;
				salary%=5;
			}
			if(salary>=2){
				sum+=salary/2;
				salary%=2;
			}
			if(salary>=1){
				sum+=salary;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
