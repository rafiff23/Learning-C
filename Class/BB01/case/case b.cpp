#include <stdio.h>
#include <string.h>

int main (){
	char kata [100];
	
	scanf("%s", kata);
	
	int length = strlen(kata);
	
	
	if (length<=10){
		printf ("%s", kata);
		
	} else{
		printf("%c%c%d%c", kata[0], kata [1], length-2, kata[length-1]);	
	}
	return 0;
}

