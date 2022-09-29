#include <stdio.h>

int main() {
    int T;
    int N;
    int p[T];
    int a[T];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        int x[N];
        int sum = 0;
        for(int j=0;j<N;j++)
        {
            scanf("%d",&x[j]);
            sum += x[j];
        }
        a[i] = 4 * sum;
        p[i]=4*N;
        for(int j=0;j<N;j++)
        {
            if(j==0)
            {
                p[i]=p[i]+2*x[j];
                if(N>1)
                {
                    if((x[0]-x[1])>0)
                        p[i]+=(x[0]-x[1])*2;
                }
                else
                {
                    p[i]+=2*x[j];
                }
            }
            else if(j==N-1 && N>1)
            {
                p[i]=p[i]+2*x[j];
                if((x[j]-x[j-1])>0)
                        p[i]+=(x[j]-x[j-1])*2;
            }
            else
            {
                if((x[j]-x[j-1])>0)
                        p[i]+=(x[j]-x[j-1])*2;
                if((x[j]-x[j+1])>0)
                        p[i]+=(x[j]-x[j+1])*2;
            }
        }
    }
    for (int i=0; i<T; i++) 
    {
        printf("Case #%d: %d %d\n", (i+1), p[i], a[i]);
    }
    return 0;
}
