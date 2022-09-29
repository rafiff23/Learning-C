#include <stdio.h>
#include <string.h>
int main(){
	
	char s[150];
    int t,len=0,j;
    
    scanf("%d",&t);
    for(int i=0;i<t;i++){
    	int word=1;

    	scanf("%d\n",&len);
    	scanf("%[^\n]",s);
    	for(j= 0; s[j] != '\0'; ++j){
    		if(s[j]==' '&& s[j+1]!=' ')			
			word++;
		}
	  if(s[j-1]==' ')word--;
      if(s[0]==' ')word--;
      if(s[0]=='\0')word--;
      
      printf("Case #%d: %d\n",i+1,word);
	}
    return 0;
}
