#include<stdio.h>

int main() {
	int angka = 0;
	int x,y;
	scanf("%d",&angka);
	
	int mt[angka]={0};
	
	for(x=1;x<=angka;x++) {
		scanf("%d",&mt[x]);
	}

	for(x=9;x>=1;x--) {
		for(y=1;y<=angka;y++) {
			if(mt[y] == x){
				printf("#");
			}
			else 
				printf(".");
		}
		
		printf("\n");
	}
	
	return 0;
}
