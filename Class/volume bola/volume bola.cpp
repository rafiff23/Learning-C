#include <stdio.h>
#include <math.h>
int main(){
	printf("menghitung volume bola\n");
	printf ("testcase: ");
	int t;
	scanf ("%d", &t);
	double a, b;
	for(int i=1;i<=t;i++) {
	printf ("Masukkan Diameter Dari Bola: ");
	scanf ("%lf", &a);
	a = a/2;
	printf ("Maka Radius Dari Bola Tersebut Adalah: %.2f\n", a);
	b= (4.0/3.0) * (22.0/7.0) * pow(a,3.0);
	if (a>0){
	printf ("Case #%d := %.2f\n\n", i, b);
	t++;
	}
	else{
		printf("null\n\n");
	}
}
	return 0;

}
