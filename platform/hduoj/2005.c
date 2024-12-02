#include <stdio.h>

int main(){
	int i;
	int y,m,d,res;
	int ms[]={31,28,31,30,31,30,31,31,30,31,30};
	while(scanf("%d/%d/%d",&y,&m,&d)==3){
		res=d;
		for(i=0;i<m-1;i++)
			res+=ms[i];
		if(y%4==0&&y%100!=0||y%400==0){
			if(m>2) 
				res+=1;
		}
		printf("%d\n",res);
	}
	return 0;
}
