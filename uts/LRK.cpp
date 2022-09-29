#include <stdio.h>
	int main (){
	 long long int x,y,z; 
	 long long int temp,total,a,b,m=0;
	 scanf("%lld %lld %lld",&x,&y,&z);
	 long long int k[x+1];
	 k[0]=0;
	 
	 for(int i = 1; i<=x ; i++){
		scanf("%lld",&temp);
		if(i%z==0){
		   		m+=temp;
		   		k[i]=m;
	  		}
	 	}
	 
	 for(int j = 1 ; j<=y ; j++){
	  	scanf("%lld %lld",&a,&b);
	 	 total=0;
	  
	   if(a!= b){
	      	if(a%z!=0){
	       	while(a%z != 0)
	       	a++;
	      	}
	      	if(b%z!=0){
	      	while(b%z!=0)
	      	b--;
	      	}
		}
	   
	  	if(b==a && b%z!=0){
	   	}else{
	    	total=k[b]-k[a-z];
	   	}
	   	printf("%lld\n",total);
	 	}
	 return 0;
	}
