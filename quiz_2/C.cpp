#include <stdio.h>

int main()
{
	long long int temp,N;
	int tc;
	double sum,mean,median;
	scanf("%d",&tc);

	
	for(int i = 0 ; i < tc ; i++){
		scanf("%lld",&N);
		long long int a[N+1];
		for(int j = 0 ; j < N ; j++){
			scanf("%lld",&a[j]);
		}
	
		for(int k = 0 ; k < N-1 ; k++ ){
			for(int l = N-1 ; l > k ; l-- ){
				if(a[l] < a[l-1]){
					temp=a[l];
        			a[l]=a[l-1];
        			a[l-1]=temp;
        		}
        	}	
    	}
    	for(int p = 0 ; p < N ; p++ ){
    		sum += a[p]*1.0;
		}
		mean = sum/N;
   			if( N%2 != 0){
   	 			median=(double)a[N/2];
    		}
  			else if(N%2==0) {
    			median=((double)a[N/2]+(double)a[N/2-1])/2;
   			}
		
		printf("Case #%d:\n",i+1);
		printf("Mean : %.2f\n",mean);
		printf("Median : %.2f\n",median);
		sum = 0;
		mean = 0;
		median = 0;
	}
	
	return 0;
}
