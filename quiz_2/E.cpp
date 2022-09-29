#include <stdio.h>

void swap(long *a,long *b)
{
    long temp=*a;
    *a=*b;
    *b=temp;
}

void sort(long array[],int N)
{
   for(int i=0;i<N;i++)
   {
       for(int j=0;j<N-i;j++)
       {
            if(array[j] > array[j+1])
            {
                swap(&array[j],&array[j+1]);    
            }
       }
   }
} 

int main()
{
    int T;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++)
    {
        int N;
        
        scanf("%d",&N);
        
        long array[5000]={0};
        long temp[5000]={0};
        
        for(int j=0;j<N;j++)
        {
            scanf("%ld",&array[j]);
            temp[j]=array[j];
        }
        
        sort(temp,N-1);
        
        int tisis=1;
        
        long ctr[5000]={0};

  for(int j=0;j<N;j++)
        {
            ctr[tisis]=temp[j];
            if(temp[j]!=temp[j+1])
            {
                tisis++;
            }
        }
        
        printf("Case #%d:",i+1);
        
        for(int j=0;j<N;j++)
  {
            for(int k=1;k<=tisis;k++)
            {
                if(ctr[k] == array[j])
                {
                    printf(" %d",k);
                    break;
                }
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
