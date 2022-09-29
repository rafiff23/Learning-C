#include <stdio.h>
#include<stdlib.h>
 // A comparator function used by qsort 
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 
//binary search function
 int search(int *array,int first, int last, int search)
 {
  int middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      return middle+1;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a, n, sizeof(int), compare);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int query;
        scanf("%d",&query);
        printf("%d\n",search(a,0,n-1,query));
    }

    return 0;
}
