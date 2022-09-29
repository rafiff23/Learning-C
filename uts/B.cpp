#include<stdio.h>
int main(){
 int test;
 scanf("%d",&test);
 for(int i=0;i<test;i++){
  int kapasitas, merah, hitam;
  int detik=0;
  scanf("%d %d %d",&kapasitas,&merah,&hitam);
  int temp1 = merah;
  int temp2 = hitam;
  int a=hitam+merah;
  while(a<=kapasitas){
   detik++;
   merah=temp1;
   hitam=temp2;
   if(detik%4==0){
    temp1 = temp1 - (temp1/3);
   }
   else if (detik%4!=0){
    temp1= temp1*2;
   }
   if(detik%3==0){
    temp2= temp2-((temp2*4)/5);
   }
   else if(detik%3!=0){
    temp2= temp2*3;
   }
   a=temp1+temp2;
  }
  printf("Case #%d: %d",i+1,detik-1);
  if(hitam>merah){
   printf(" Black %d\n",hitam-merah);
  }
  else if(merah>hitam){
   printf(" Red %d\n", merah-hitam);
  }
  else{
   printf(" None 0\n");
  }
 }
 
 return 0;
}
