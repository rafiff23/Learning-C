#include <stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "r");
	int tc,tc2,K=0,L=0;
	int N[111];
	
	fscanf(fp,"%d",&tc);
	for(int i = 0 ; i < tc ; i++){
		fscanf(fp,"%d",&tc2);
		for(int j = 0 ; j < tc2 ; j++){
			fscanf(fp,"%d",&N[j]);
		}
		for(int j = 0 ; j < tc2 ; j++){
			L += 4*N[j];
			K += (8*N[j] - (4*(N[j]-1)));
			if(j!= tc2-1){
				if(N[j] >= N[j+1]){
					K -= 4*N[j+1];
				}else{
					K -= 4*N[j];
				}
			}
		}
		printf ("Case #%d: %d %d\n",i+1,K,L);
		K = 0;
		L = 0;
	}
	fclose(fp);
	return 0;
}
