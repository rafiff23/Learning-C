#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct tm waktu;
int main (){
	
//typedef struct waktu;

		time_t currentTime;
		time (&currentTime);

		waktu *myTime = localtime(&currentTime);
		printf ("%d/%d/%d\n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		printf ("%d-%d-%d", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
}
