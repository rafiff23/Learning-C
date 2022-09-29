#include <stdio.h>
#include <conio.h>

int main (void)
{
	int x;
	int y;
	char bank[12][20] = {"MANDIRI", "BCA", "BTPN", "BRI", "MUAMALAT", "DKI", "MEGA", "DANAMON", "CIMB NIAGA", "MAYBANK", "BJB","SINARMAS"};
	  for(x=0;x<12;x++) {
	 printf ("%d. bank %s\n" ,x+1,bank[x]);}
	 
	 printf ("pilih bank: ");
	 scanf ("%d", &y);
	 if (y == 1){
	 
	 printf ("Mandiri");}
	
	if (y==2){
		printf ("BCA");
	}
	
	printf ("bank yang dipilih %d%s", &y);

	return 0;
	
//	getch();
//	return 0;
}



