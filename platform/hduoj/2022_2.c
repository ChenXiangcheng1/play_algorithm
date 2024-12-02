#include <stdio.h>

int main(){
	int i;
	int m,n,score,maxind,maxscore;
	while(scanf("%d%d",&m,&n)==2){
		maxind=0;
		scanf("%d",&maxscore);
		for(i=1;i<m*n;i++){
			scanf("%d",&score);
			if(abs(score)>abs(maxscore)){
				maxscore=score;
				maxind=i;
			}
		}
		printf("%d %d %d\n",maxind/n+1,maxind%n+1,maxscore);
	}
	return 0;
}
