#include <stdio.h>
//#include <stdlib.h>
int main () {
		int M,i,j ;
		scanf("%d", &M);
		char x,y;
		char xxx[2];
		scanf("%s",xxx);
		x = xxx[0];
		scanf("%s",xxx);
		y = xxx[0];
		for(i=0;i<M;i++) {
			for(j=0;j<M;j++) {
				if(i==j || i+j == M-1)
					printf("%c",x);
					else
					printf("%c",y);
					
			}
			printf("\n");
		}
		return 0;
}

