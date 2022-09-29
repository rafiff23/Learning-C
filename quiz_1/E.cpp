#include <stdio.h>

int main(){
	FILE *fp;
	
	fp = fopen("testdata.in", "r");
	
	int T, N, M;
	char c;
	fscanf(fp, "%d\n", &T);
	
	for(int k=0;k<T;k++){
		fscanf(fp, "%d %d\n", &N, &M);
		
		char str[N+10][M+10];
		for(int i=0;i<N;i++){
			fscanf(fp, "%s\n", str[i]);
		}
		
		int top = 0;
		int bottom = N-1;
		int left = M-1;
		int right = 0;
		bool topDone = false;
		bool leftDone;
		int leftMin = M;
		int rightMax = -1;
		for(int i=0;i<N;i++){
			bool dot = true;
			leftDone = false;
			for(int j=0;j<M;j++){
				if(str[i][j]!='.') {
					dot = false;
					if(!leftDone){
						left = j;
						leftDone = true;
					}
					right = j;
				}
			}
			
			if(leftMin > left){
				leftMin = left;
			}
			
			if(rightMax < right){
				rightMax = right;
			}
			
			if(!topDone){
				if(!dot){
					top = i;
					topDone = true;
				}
			}
			
			if(!dot){
				bottom = i;
			}
		}
		
		printf("Case #%d:\n", k+1);
		printf("%d %d\n", bottom-top+1, rightMax-leftMin+1);
		for(int i=top;i<=bottom;i++){
			for(int j=leftMin;j<=rightMax;j++){
				printf("%c", str[i][j]);
			}
			printf("\n");
		}
	}
	
	fclose(fp);
	return 0;
}
