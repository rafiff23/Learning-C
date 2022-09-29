#include <stdio.h>
#include <string.h>

int main (){
	char arr [150];
	
	scanf ("%s", arr);
	getchar();
	
	int f;
	scanf("%d", &f);
	int len = strlen(arr);
	int amount = 0;
	char first = arr[0];
	int sign = 0;
	
	for (int i = f; i>0; i--){
		if (arr[sign]==first){
			amount++;
		}
		sign++;
		if (sign == len){
			sign = 0;
		}
	}
	printf ("%d\n", amount);
	return 0;
}
