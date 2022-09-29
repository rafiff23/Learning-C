#include<stdio.h>

int main(){
        int t;
        int n, depan, depan1, belakang, belakang1, pages;
        scanf("%d", &t);
        for(int i=1; i<=t; ++i){
                printf("Case #%d:", i);
             
                scanf("%d", &n);
                if(n % 4 == 0){
                        pages = n / 4;
                }else{
                        pages = (n / 4) + 1;
                }
                depan = pages * 4;
                depan1 = 1;
                belakang = 2;
                belekang1 = depan - 1;
                for(int j=1; j<=pages; ++j){
                        printf("\nSheet %d, front: ", j);
                        if(depan>0 && depan<=n)
                                printf("%d, ", depan);
                        else
                            printf("Blank, ");
                        if(depan1>0 && depan1<=n)
                                printf("%d", depan1);
                        else
                            printf("Blank");
                        printf("\nSheet %d, back: ", j);
                        if(belakang>0 && back1<=n)
                                printf("%d, ", back1);
                        else
                            printf("Blank, ");
                        if(belakang1>0 && back2<=n)
                                printf("%d", back2);
                        else
                            printf("Blank");
                        depan = depan - 2;
                        depan1 = depan1 + 2;
                        belakang = belakang + 2;
                        belakang1 = belakang1 - 2;
                }
                printf("\n");
        }
        return 0;
}
