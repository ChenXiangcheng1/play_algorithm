#include <stdio.h>

int main(){
	int i,j;
	int n,m,count;
	// double scores[51][6];
	while(scanf("%d%d",&n,&m)==2){
		double scores[n+1][m+1];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%lf",&scores[i][j]);
			}
		}
        // 计算n个学生的平均成绩
		for(i=0;i<n;i++){
			scores[i][m]=0;
			for(j=0;j<m;j++){
				scores[i][m]+=scores[i][j];
			}
            scores[i][m]/=m;
		}
		// 计算m门课的平均成绩
		for(i=0;i<m;i++){
			scores[n][i]=0;
			for(j=0;j<n;j++){
				scores[n][i]+=scores[j][i];
			}
			scores[n][i]/=n;
		}
		// 计算各科成绩均大于等于平均成绩的学生数量
		count=n;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(scores[i][j]<scores[n][j]){
					count--;
					break;
				}
			}
		}
        // 打印输出
        for(i=0;i<n-1;i++){
            printf("%.2lf ",scores[i][m]);
        }
        printf("%.2lf\n",scores[n-1][m]);
        for(i=0;i<m-1;i++){
            printf("%.2lf ",scores[n][i]);
        }
        printf("%.2lf\n",scores[n][m-1]);
		printf("%d\n\n",count);
	}
	return 0;
}
