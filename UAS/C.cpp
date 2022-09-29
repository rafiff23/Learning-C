#include<stdio.h>
#include<string.h>

struct status{
		int uang;
	char name[50];
	char idnumber[50];
};

int main(){
	FILE*fp = fopen("testdata.in","r");
	int t;
	fscanf(fp,"%d\n",&t);
	status pengguna[100];
	int orang=0,dana=0;
	char limit[100];
	for(int i = 0 ; i < t ; i++){
		fscanf(fp,"%[^,],%[^,],%d\n",&pengguna[i].idnumber,&pengguna[i].name,&pengguna[i].uang);
	}
	fscanf(fp,"%s",limit);
	for(int j = 0 ; j < t ; j++){
		if(strcmp(limit,pengguna[j].idnumber) == 0){
		printf("%s %s %d\n",pengguna[j].idnumber,pengguna[j].name,pengguna[j].uang);
		orang+=1;
		dana = pengguna[j].uang + dana;
		}
	}
	printf("Total Recipients: %d\n",orang);
	printf("Total Amount: %d\n",dana);
	
	fclose(fp);
	
	return 0;
}
