#include <stdio.h>
#include <string.h>

int main (){
	int t;
	scanf ("%d", &t);
	getchar();
	char x[100];
	int jumlah;
	int l;
	for (int i=0;i<t;i++){
		scanf("%d", &jumlah);
		getchar();
		x[jumlah];
		int huruf=0;
		gets(x);
		l=strlen(x);
		for (int i =0; i<l; i++){
			if (x[i]!= ' '&& x[i]!='\t'){
				huruf++;
				while (x[i]!=' ' && x[i] != '\t'){
					i++;
				}
			}
		}
		printf ("Case #%d: %d\n", i+1, huruf);
	}
	return 0;
}
