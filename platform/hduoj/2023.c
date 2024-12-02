#include <stdio.h>
#include <string.h>

int main(){
	int i,j;
	int n,m,count;
	int flag[50][5];
	double scores[50][5];
	double scoavg,stuavg;
	while(scanf("%d%d",&n,&m)==2){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%lf",&scores[i][j]);
			}
		}
		// 计算n个学生的平均成绩
		for(i=0;i<n;i++){
			scoavg=0;
			for(j=0;j<m;j++){
				scoavg+=scores[i][j];
			}
			scoavg/=m;
			if(i==n-1){
				printf("%.2lf\n",scoavg);
			}else{
				printf("%.2lf ",scoavg);
			}
		}
		// 初始化用于计算count的flag
		for(i=0;i<n;i++){
			memset(flag[i],0,m*4);
		}
		// 计算m门课的平均成绩
		for(i=0;i<m;i++){
			stuavg=0;
			for(j=0;j<n;j++){
				stuavg+=scores[j][i];
			}
			stuavg/=n;
			if(i==m-1){
				printf("%.2lf\n",stuavg);
			}else{
				printf("%.2lf ",stuavg);
			}
			// 计算各科成绩均大于等于平均成绩的学生flag
			for(j=0;j<n;j++){
				if(scores[j][i]>=stuavg){
					flag[j][i]=1;
				}
			}
		}
		// 计算各科成绩均大于等于平均成绩的学生数量
		count=n;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(flag[i][j]==0){
					count--;
					break;
				}
			}
		}
		printf("%d\n\n",count);
	}
	return 0;
}
