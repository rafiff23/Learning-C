#include <stdio.h>

int main (){
	int n,m,a;
	
	scanf ("%d %d %d", &n, &m, &a);
	if (n % a != 0){
		n = (n/a)+1;
	}else{
		n = n/a;
	}
	if (m % a != 0){
		m = (m/a)+1;
	}else{
		m = m/a;
	}
	printf ("%d",n*m);
}
