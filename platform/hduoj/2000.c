#include <stdio.h>

void swap(char *a,char *b){
//	char tmp=*a;
//	*a=*b;
//	*b=tmp;

	*a^=*b;  // °´Î»Òì»ò a=110 b=011 => a=101 
	*b^=*a;  // b=110
	*a^=*b;  // a=011
}

int main(){
    char a,b,c;
    while(3==scanf("%c%c%c",&a,&b,&c)){
    	getchar();
		if(b<a){
			swap(&a,&b);
		}
		if(c<a){
			swap(&a,&c);
		}
		if(c<b){
			swap(&b,&c);
		}
		printf("%c %c %c\n",a,b,c);
    }
    return 0;
}

