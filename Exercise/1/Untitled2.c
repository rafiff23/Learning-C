#include <stdio.h>

int main()
{
	int age = 18; //angka bulat
	double gpa = 3.6; //desimal
	char grade = 'a'; // 1 huruf
	char prase [] = "rafif"; //banyak huruf
	
	printf ("hello world\n");
	
	//  (\n buat enter)
	
	printf ("my favorite %s is %d\n", "number", 90); // %f buat angka desimal %s untuk huruf yg banyak %c buat 1 huruf
	
	printf ("my age is %d  my gpa are %f im in the grade %c and my name is %s\n" ,age ,gpa, grade, prase ); 
	
	int num = 18 - 8;
	printf ("%d\n", 4 + 5 * num);
	
	//pow -> pangkat 2, sqrt -> akar 2, ceil -> ngebuletin keatas, floor ->ngebuletin kebawah
	
	printf ("%f\n", sqrt (49) );
	printf ("%f\n", ceil (gpa));
	printf ("%f\n", pow (num, 2));
    
	/*	selain /\ bisa juga dipake */
    // const int ngebuat nilai yang ada di int gabisa diubah -> bikin program gabisa jalan
	
	int umur;
	printf ("enter your age: ");
	scanf ("%d", &umur);
	printf ("so your age is %d away from me\n", umur - 18);
	
	int nama;
	printf ("enter your name: ");
	scanf ("%s", &nama);
	printf ("nice name u got there\n");
	
	int ipk;
	printf ("enter your gpa dreams: ");
	scanf ("%f", &ipk);
	printf ("okay goodluck!");
	return 0;
	
}
