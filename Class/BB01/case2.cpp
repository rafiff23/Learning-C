#include <stdio.h>

int main (){
	int k;
	scanf ("%d", &k);
	int arr[k];
	
	for (int i = 0; i < k; i++){
		scanf ("%d", arr[i]);
	}
	int max = 0;
	int tempteam = 0;
	
	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			if (arr[j]- arr[i] <= 5 && arr[j]-arr[i >=0]){
				tempteam++;
			}
		}
		if (tempteam >= max){
			max = tempteam;
		}
		tempteam = 0;
	}
	printf ("%d\n", max);
	
	return 0;
}
