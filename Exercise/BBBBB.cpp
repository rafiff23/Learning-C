#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char input[120];
        scanf("%[^\n]",input);
        getchar();
        long long int len=strlen(input),a=0,b=0;
        char string[100][120];
        for(long long int j=0;j<len;j++)
        {
            if(input[j]!=' ')
            {
                string[a][b]=input[j];
                b++;
            }
            else if(input[j]==' ')
            {
                a++;
                b=0;
            }
        }
        printf("Case #%d:",i+1);
        for(int j=0;j<=a;j++)
        {
            int length=strlen(string[j]);
             if(length==4)
            {
                for(long long int m=1,n=length-2;m<n;m++,n--)
                {
                    char tmp=string[j][m];
                    string[j][m]=string[j][n];
                    string[j][n]=tmp;
                }
            }
            else if(length>4)
            {
                long long int mid=length/2;
                for(long long int m=1,n=length-2;m<n,n!=mid;m++,n--)
                {
                    char tmp=string[j][m];
                    string[j][m]=string[j][n];
                    string[j][n]=tmp;
                }
            }
            printf(" %s",string[j]);
        }
        printf("\n");
    }
    return 0;
}
