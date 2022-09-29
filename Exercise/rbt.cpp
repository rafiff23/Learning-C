#include <stdio.h>
#include <stdlib.h>

int main() {
   int* arr = (int*)malloc(sizeof(int)*6);
   int i;
   for(i = 0;i<6;i++){
      arr[i] = i+1;
   }
   //Index starts from 0
   //So, 4th element menas arr[3]
   printf("4th element = %d\n",arr[3]);
   return 0;
}

int height(Node node){
        if (node == null){
            return 0;
        }
        else{
            return 1 + Math.max(height(node.left), height(node.right));
        }
}

boolean isHeightBalanced(Node node)
{
        if (node == null){
            return true;
        }
        int left = height(node.left);
        int right = height(node.right);

        if (Math.abs(left - right) <= 1
                && isHeightBalanced(node.left)
                && isHeightBalanced(node.right)){
            return true;
        }
        return false;
}
