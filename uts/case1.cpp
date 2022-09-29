#include<stdio.h>
int main(){
 	int T;
 	scanf("%d",&T);
 	for(int i=1;i<T;i++){
  		long long int capacity, black, red;
  		long long int a=black+red;
  		long long int waktu=0;
  		long long int tmp1 = red;
  		long long int tmp2 = black;
  		scanf("%d %d %d",&capacity,&red,&black);
  		while(a<=capacity){
   			waktu++;
   			red=tmp1;
   			black=tmp2;
   			if(waktu%4==0){
    			tmp1 = tmp1 - (tmp1/3);
   			}
   			else if (waktu%4!=0){
    		tmp1= tmp1*2;
   			}
   			if(waktu%3==0){
    			tmp2= tmp2-((tmp2*4)/5);
   			}
   			else if(waktu%3!=0){
    		tmp2= tmp2*3;
   			}
   			a=tmp1+tmp2;
  		}
  		printf("Case #%d: %d",i,waktu-1);
  		if(black>red){
   			printf(" Black %d\n",black-red);
  		}
  		else if(red>black){
   			printf(" Red %d\n", black-red);
  		}
  		else{
   			printf(" None 0\n");
  		}
 	}
 	return 0;
}
