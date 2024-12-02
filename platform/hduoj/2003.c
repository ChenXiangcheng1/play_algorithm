#include <stdio.h>

int main(){
	double n;
	while(1==scanf("%lf",&n)){
		if (n<0) n=0-n;
		printf("%.2f\n",n);
	}	
	return 0;
}
