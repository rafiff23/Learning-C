#include <stdio.h>
#include <string.h>

void merge (int arr[] , int l , int m , int r , int temp[]){
 int n1 = m - l + 1 ;
 int n2 = r - m ;
 
 int L[n1] , R[n2] ;
 int A[n1] , B[n2] ;
 
 for (int i = 0 ; i < n1 ; i++){
  L[i] = arr[l+i] ;
  A[i] = temp[l+i] ;
 }
 for (int j = 0 ; j < n2 ; j++){
  R[j] = arr[m+1+j] ;
  B[j] = temp[m+1+j] ;
 }
 
 int i = 0 ;
 int j = 0 ;
 int k = l ;
 
 while (i < n1 && j < n2){
  if (L[i] >= R[j]){
   arr[k] = L[i] ;
   temp[k] = A[i] ;
   i++ ;
  }else {
   arr[k] = R[j];
   temp[k] = B[j] ;
   j++ ;
  }
  k++ ;
 }
 while (i < n1){
  arr[k] = L[i];
  temp[k] = A[i] ;
  k++ ;
  i++ ;
 }
 while (j < n2){
  arr[k] = R[j];
  temp[k] = B[j] ;
  k++ ;
  j++ ;
 }
}

void mergesort(int arr[] , int l , int r , int temp[]){
 if (l < r){
  int m = l + (r-l) / 2 ;
  
  mergesort (arr , l , m , temp) ;
  mergesort (arr , m+1 , r , temp);
  
  merge (arr , l , m , r , temp );
 }
}

int main(){
 FILE *fp = NULL ;
 fp = fopen("testdata.in" , "r") ;
 
 char title[105][1005] = {0} , artist[105][1005] ={0} ;
 int view[105] = {0} , temp[105] = {0};
 int n = 0 ;
 
 while(!feof(fp)){
  temp[n] = n ;
  fscanf (fp , "%[^#]#%[^#]#%d\n" , &title[n] , &artist[n] , &view[n]) ;
  n++ ;
 }
 
 mergesort (view , 0 , n-1 , temp);
 
 for (int j = 0 ; j < n ; j++){
   for (int k = j+1 ; k < n ; k++){
    char cek[55] = {0} ;
    if (view[j] == view[k] ){
     if(strcmp (title[temp[j]] , title[temp[k]]) > 0){
      strcpy (cek , title[temp[j]]) ;
      strcpy (title[temp[j]] , title[temp[k]]) ;
      strcpy (title[temp[k]] , cek) ;
      
      strcpy (cek , artist[temp[j]]) ;
      strcpy (artist[temp[j]] , artist[temp[k]]) ;
      strcpy (artist[temp[k]] , cek) ;
     }
    }
   }
  }
 
 for (int i = 0 ; i < n ; i++){
  printf ("%s by %s - %d\n" , title[temp[i]] , artist[temp[i]] , view[i]);
 }
 
 fclose(fp);
 
 return 0 ;
}
