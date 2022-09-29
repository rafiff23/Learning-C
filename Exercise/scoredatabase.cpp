#include <stdio.h>

struct data{
	char ID[25];
	char Name[105];
	char Score[15];
};

int main(){
    int N;
    scanf("%d",&N);getchar();
	struct data mhs[N+1];
	for(int i=1;i<=N;i++){
		scanf("%s",&mhs[i].ID);getchar();
		scanf("%[^\n]",&mhs[i].Name);getchar();
		scanf("%[^\n]",&mhs[i].Score);getchar();
	}
	int Q,q;
	scanf("%d",&Q);
	for(int j=1;j<=Q;j++){
		scanf("%d",&q);
		for(int k=1;k<=Q;k++){
			if(k==q){
				printf("Query #%d:\n",j);
				printf("ID: %s\n",mhs[k].ID);
				printf("Name: %s\n",mhs[k].Name);
				printf("Score: %s\n",mhs[k].Score);
   			}
  		}
 	}
 	return 0;
}
