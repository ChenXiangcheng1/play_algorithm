#include <stdio.h>

void swap(int *n,int *m){
	*n^=*m;
	*m^=*n;
	*n^=*m;
}

int main(){
	int i;
	int n,m,oddres,evenres;
	while(scanf("%d%d",&n,&m)==2){
		if(n>m){
			swap(&n,&m);
		}
		oddres=0,evenres=0;
		for(i=n;i<=m;i++){
			if(i&1){
				oddres+=i*i*i;	
			}else{
				evenres+=i*i;	
			}			
		}
		printf("%d %d\n",evenres,oddres);
	}	
	return 0;
}
