#include <stdio.h>
#include <math.h>

int volume(int radius){
	int sum;
	
	sum = (4.0/3.0) * (22.0/7.0) * pow(radius,3.0);;
	return sum;
}

int main (){
	int radius,b,c,t;
	char d,e,f;
	printf ("Volume of a sphere \n");
	printf("Input testcase: ");
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf ("input radius: ");
		scanf("%d", &radius);
		int sum2 = volume(radius);
		if(radius>0) {
			printf("Case #%d: %d\n", i+1, sum2);
		}else{
			printf ("Null\n");
		}
	}
	return 0;
}
