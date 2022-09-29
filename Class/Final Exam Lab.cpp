#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define size 100

struct Data{
 	char nama[100];
 	char password[100];
 	char strength[100];
 	int i;

 	struct Data *next,*prev;
}*head[size],*tail[size],*curr;

	int hashing(char nama[100]){
 		int key=0;
 
 for(int i=2;i<strlen(i);i++){
  key += id[i];
 }
 return key % size;
}

void view(){
 for(int i=0;i<size;i++){
   
   if(head[i]!=NULL){
    
   curr=head[i];
  
   while(curr){
     printf("======================\n");
    printf("Passwor = :%s ",curr->password);
    
    
    printf("\nUsername:%s \nPassword:%s \nPlatform:%s \nHeight:%d \nStrenght:%d \n",curr->nama,curr->password,curr->strength);
    
    curr=curr->next;
   }
   
   printf("\n");
   } 
  }
}

	void menu(){
 		printf("1.View Accounts\n");
 		printf("2.Insert Acccount\n");
 		printf("3.delete Account\n");
 		printf("4.exit\n");
}

void insert(char nama[100],char password[100]){
 int index=hashing(nama);
 
 	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
 	strcpy(node->nama,nama);
 	strcpy(node->password,password);
 	node->next = node->prev = NULL;
 
 	if(head[index]==NULL){
  		head[index] = tail[index] = node;
 }
 	else{
  		tail[index]->next=node;
  		node->prev=tail[index];
 	 	tail[index]=node;
 	}
}

	void removing(char nama[100],char password[100]){
 		int index=hashing(nama);
 
 	if(head[index]==NULL){
  	printf("tidak ada data\n");
  	return;
 }
 
 else{
  if(strcmp(head[index]->password,passowrd)==0){
   if(head[index]==tail[index]){
    free(head[index]);
    head[index]=tail[index]=NULL;
   }
   
   else{
    curr=head[index];
    head[index]=head[index]->next;
    free(curr);
    head[index]->prev=NULL;
    
   }
   
  }
  
  else if(strcmp(tail[index]->nama,nama)==0){
   curr=tail[index];
   tail[index]=tail[index]->prev;
   free(curr);
   tail[index]->next=NULL;
  }
  
  else{
   curr=head[index];
   
   while(strcmp(curr->nama,nama)>0){
    curr=curr->next;
   }
   curr->prev->next=curr->next;
   curr->next->prev=curr->prev;
   free(curr);
  }
  
 }
 
}

int main (){
		char name[100];
 		char Password[100];
 		char Strength[100];
 		int pil;
 		
 		do{
  system("cls");
  menu();
  
  do{
   printf(">>");
   scanf("%d",&pil);
   getchar();
  }while(pil<1||pil>4);
  
  if(pil==1){
   system("cls");
   
do{
    printf("Put Username 6 - 20");
    gets(name);
    
   }while(  strlen(name)<6 || strlen(name)>20 );
   
   do{
    printf("Password must be valid 6 - 20");
    gets(type);
    
   }
   insert( name, password);
  }

