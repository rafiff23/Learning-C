#include <stdio.h>
int main(){
 int a,b;
 long long int total=0;
 long long int angka[1005],angka2[1005];
 scanf("%d",&a);
 for(int e=0;e<a;e++){
  scanf("%d",&b);
  for(int y=0;y<b;y++){
   scanf("%lld",&angka[y]);
  }
  for(int x=0;x<b;x++){
   scanf("%lld",&angka2[x]);
  }
   int temp=0;
 for(int x=0;x<b;x++){
  for(int y=x+1;y<b;y++){
   if(angka[y]>angka[x]){
    temp=angka[x];
    angka[x]=angka[y];
    angka[y]=temp;
   }
  }
 }
 int temp1=0;
 for(int x=0;x<b;x++){
  for(int y=x+1;y<b;y++){
   if(angka2[y]<angka2[x]){
    temp1=angka2[x];
    angka2[x]=angka2[y];
    angka2[y]=temp1;
   }
  }
 }
  for(int w=0;w<b;w++){
          total+=angka[w]*angka2[w];
  }
  printf("Case #%d: %lld\n",e+1,total);
  total=0;
  }
 return 0;
}
