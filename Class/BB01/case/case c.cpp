#include <stdio.h>

int main (){
	int x,y;
	
	scanf ("%d %d", &x, &y);
	x = (x / 10) + (y % 10);
	if (x % 2 == 0){
		printf ("even");
	}else {
		printf ("odd");
	}
	
	return 0;
}
