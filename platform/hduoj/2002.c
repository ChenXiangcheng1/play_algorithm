#include <stdio.h>

#define PI 3.1415927

int main(){
	double r;
	while(1==scanf("%lf",&r)){
		printf("%.3f\n",4.0/3*PI*r*r*r);
	}	
	return 0;
}
