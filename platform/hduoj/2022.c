#include <stdio.h>

struct player{
	int row;
	int column;
	int score;
}p,pmax;

int main(){
	int i;
	int m,n;
	while(scanf("%d%d",&m,&n)==2){
		scanf("%d",&pmax.score);
		pmax.row=0,pmax.column=0;
		for(i=1;i<m*n;i++){
			scanf("%d",&p.score);
			p.row=i/n;
			p.column=i%n;
			if(abs(p.score)>abs(pmax.score)){
				pmax=p;
			}
		}
		printf("%d %d %d\n",pmax.row+1,pmax.column+1,pmax.score);
	}
	return 0;
}
