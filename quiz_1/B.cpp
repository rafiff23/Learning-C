#include<stdio.h>
#include<string.h>

int main()
{
	char a[111],b[111];
	int tc,tc2,L;
	char one,two;
	
	FILE *fp;
	fp = fopen("testdata.in","r");

	fscanf(fp,"%d",&tc);

	while(tc--){
		int count=0;
		int X[26]={0};
		int Y[26]={0};
		int tempX=0;
		int tempY=0;
		
		fscanf(fp,"%s\n",a);

		L = strlen(a);

		fscanf(fp,"%d\n",&tc2);
		for(int i = 0 ; i < tc2 ; i++){
			fscanf(fp,"%c %c\n",&one,&two);
			tempY= one - 'A';
			if(Y[tempY]==0){
				for(int j = 0 ; j < L ; j++){
					if(a[j]==one){
						a[j]=two;
					}
				}
			Y[tempY]++;
			}
		}
			
		strcpy(b,a);

		while(b[count] != '\0'){
			if(b[count] >= 'A' && b[count] <= 'Z'){
				tempX = b[count] - 'A';
				X[tempX]++;
			}
		count++;
	}
		for(count = 0 ; count < 26 ; count++){
			if(X[count] > 0){
				printf("%c %d\n", count +'A',X[count]);
			}
		}
	}
	fclose(fp);
	return 0;
}
