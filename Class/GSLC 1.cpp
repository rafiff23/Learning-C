#include <stdio.h>
#include <math.h>

int main () 
{
	
	int a, b, c;
	double average;
	int roundup,rounddown;
	scanf ("%d %d %d", &a, &b, &c);
	average = (a + b + c);
	average /= 3;
	roundup = ceil(average);
	rounddown = floor(average);
	printf ("%.1lf %d %d", average, roundup, rounddown); 
	
}
