#include <stdio.h>
#include <Math.h>

int main(){
	double x1,x2,y1,y2;
	while(4==scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)){  // double: %lf 
		printf("%.2f\n",sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
	}
	return 0;
}
