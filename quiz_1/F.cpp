#include <stdio.h>

int strlen(char *str){
	int len = 0;
	while(str[len]!='\0'){
		len++;
	}
	return len;
}

void reverse(char *str) { 
   if (*str) { 
       reverse(str+1); 
       printf("%c", *str); 
   } 
} 

int main(){
	FILE *fp;
	
	fp = fopen("testdata.in", "r");
	
	int T, noCase = 1;
	
	fscanf(fp, "%d\n", &T);
	while(!feof(fp)){
		int N, len, idx, prefixLength, right[1010] = {0}, suffixLength;
		bool sameAble;
		char str[1010][1010] = {'\0'}, strRev[1010][1010] = {'\0'}, prefix[1010] = {'\0'}, suffix[1010] = {'\0'};
		
		fscanf(fp, "%d\n", &N);
		for(int i=0;i<N;i++){
			fscanf(fp, "%[^\n]\n", str[i]);
			
			len = strlen(str[i]);
			right[i] = len-1;
		}
		
		prefixLength = 0;
		while(str[0][prefixLength]!='\0'){
			sameAble = true;
			for(int i=1;i<N;i++){
				if(str[0][prefixLength] != str[i][prefixLength]) {
					sameAble = !sameAble;
					break;
				}
			}
			if(sameAble) {
				prefix[prefixLength] = str[0][prefixLength];
				prefixLength++;
			} else break;
		}
		
		suffixLength = 0;
		while(true){
			sameAble = true;
			for(int i=1;i<N;i++){
				if(str[0][right[0]-suffixLength] != str[i][right[i]-suffixLength] || str[i][right[i]-suffixLength] == '\0' || str[0][right[0]-suffixLength] == '\0') {
					sameAble = !sameAble;
					break;
				}
			}
			if(sameAble) {
				suffix[suffixLength] = str[0][right[0]-suffixLength];
				suffixLength++;
			} else break;
		}
		
		printf("Case #%d: %s", noCase, prefix);
		reverse(suffix);
		printf("\n");
		
		noCase++;
	}
	fclose(fp);
	
	return 0;
}
