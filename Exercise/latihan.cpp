#include <stdio.h>
#include <string.h>

//void change (int *a){
//	*a = 10;
//}

//void swap(int *a, int *b){
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

struct student{
	char nim[10];
	char name [50];
	int age;
	float gpa;
	bool pass;
};


int main(){

student st;

strcpy(st.nim, "244057741");
strcpy(st.name, "Rafif");
st.age = 19;
st.gpa = 3.6;
st.pass = true;

printf ("NIM: %s\n", st.nim);
printf ("NAME: %s\n", st.name);
printf ("AGE: %d\n", st.age);
printf ("GPA: %f\n", st.gpa);
printf ("Pass: %s\n", st.pass? "yes":"no");
	
//int arr [10] = {4,5,6,7,8,9};

//printf ("arr: %d\n", arr[1]);
//printf ("arr: %d\n", arr[3]);

//printf ("arr: %d\n", arr[5]);

//arr[5]=10;
//printf ("arr: %d\n",arr[5]);
	
//	int val = 20;
//	int num = 15;
	
//	swap (&val, &num);
//	printf ("val : %d", val);
//	printf ("num : %d", num);
//	int *pointer;
	
//	pointer = &val;
	
//	printf ("value: %d\n", val);
//	printf ("pointer: %d\n", *pointer);	
	//change (&val);
	//printf ("value 2: %d \n", val);
	return 0;
}
