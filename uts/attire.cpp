#include <stdio.h>
#include <stdlib.h>
int main() {
        int N,i,j;
        scanf("%d",&N);
        char x,y;
        char tmp[2];
        scanf("%s",tmp);
        x = tmp[0];
        scanf("%s",tmp);
        y = tmp[0];
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) {
                if(i==j || i+j == N-1)
                    printf("%c",x);
                else
                    printf("%c",y);
            }
            printf("\n");
        }
        return 0;
}
