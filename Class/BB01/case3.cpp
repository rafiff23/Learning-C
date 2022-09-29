#include <stdio.h>
#include <string.h>

int main (){
	int x;
	scanf ("%d", &x);
	getchar();
	for (int n = 0; n < x; n++){
		char arr[100];
		scanf("%[^\n]s", &x);
		getchar();
		int alphabet[26];
		for (int y = 0; y < 26; y++ ){
			alphabet[y]=0;
		}
		for (int y = 0; y < strlen(arr); y++){
				if (arr[y] >= 'a' && arr[y] <= 'z'){
				alphabet[(int)arr[y] - (int)'a']=1;
			}else if (arr[y] >= 'A' && arr[y] <= 'Z'){
				alphabet[(int)arr[y] - (int)'A']=1;
			}
		}
		int flag =1;
		for (int y = 0; y < 26; y++){
			if (alphabet[y]==0){
				flag=0;
				break;
			}
		}
		if (flag==1){
			printf("panagram\n");
		}else {
			printf("missing ");
			for (int y=0; y<26; y++){
				if (alphabet[y]==0){
					printf ("%c", x + 'a');
				}
			}
			printf ("\n");
		}
	}
	return 0;
}
