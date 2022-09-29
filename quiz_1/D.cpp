#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp;
	
	fp = fopen("testdata.in", "r");
	
	int T, N;
	char shortWord[110][110], oriWord[110][110], end, word[110];
	bool found;
	
	fscanf(fp, "%d\n", &T);
	for(int i=0;i<T;i++){
		fscanf(fp, "%[^#]#%s\n", shortWord[i], oriWord[i]);		
	}
	
	fscanf(fp, "%d\n", &N);
	for(int i=0;i<N;i++){
		end = '\0';
		printf("Case #%d:\n", i+1);
		do {
			fscanf(fp, "%s%c", word, &end);			
		
			found = false;
			for(int j=0;j<T;j++){
				if(strcmp(shortWord[j], word)==0){
					printf("%s", oriWord[j]);
					found = !found;
					break;
				}
			}
			
			if(!found) printf("%s", word);
			printf("%c", end);
		} while(end != '\n');
	}
	
	fclose(fp);
	
	return 0;
}
