#include <stdio.h>
int main()
{
    printf ("latihan kedua\n");
    	
	char name [50];
	printf ("fullname: ");
	fgets (name, 20, stdin);
	printf ("move on\n");
	
	/* --------------------gabisa beraturan harusnya fullname - name - grade - gpa---------------*/
	
	char grade; 
	printf ("enter your first smt grade: ");
	scanf ("%c", &grade);
	printf ("nice you got an %c keep the progress\n", grade);
	
	char name2 [20];
	printf ("enter your name: ");
	scanf ("%s", &name2);
	printf ("okay %s can you give me your nickname: ", name2);
	scanf ("%s", &name);
	
	double gpa;
	printf ("enter your gpa: ");
	scanf ("%lf" , &gpa); // make 5LF UNTUK ANGKA DESIMAL
	printf ("so your gpa in this university will turn into %f\n", gpa - 1.0);
	
	
	return 0;
}
