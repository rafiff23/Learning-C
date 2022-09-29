#include <stdio.h>//file header
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct tm waktu;                       //typedef untuk mempersingkat penulisan untuk pengcodingan waktu

int main (void)
{
//--------------------------------------------------------------------------------------------------------
 //kumpulan char
    char uss[15];
    char pass[15];
    char namatujuan [20];
    char berita [30];
    char passT[20];
    char ya[3];
    char rp[4] = "Rp.";
//kumpulan int
    int i = 0;
    int t = 0;
    int result1, result2;
    int result3, result4;
    int sw;
    int sw2;
    int x;
    int y;
    int rek;
    long long int nominal;
//kumpulan void
void getMenu();
void getInformasiAkun();
void getMenuPilihTransfer();                                 
//kumpulan time
time_t currentTime;                                                             //fungsi untuk mendapatkan waktu saat ini
time (&currentTime); 
waktu *myTime = localtime(&currentTime);
/*	----------------------------------------INFO
--------------------------------------------Nama Akun :     Rafif 
--------------------------------------------Pass Akun :     123456
--------------------------------------------Pass Transaksi: B1nusian
*/
 //--------------------------------------------------------------------------------------------------------
  login:                                            //untuk memanggil perintah dengan goto
  		printf ("=======================================================================================================================\n");
  		printf ("		              Selamat Datang di Layanan BNI Mobile Banking\n");
  		printf ("=======================================================================================================================\n");
  		printf ("\n");
    while (i < 3)                                        //awal pengulangan dimulai
    {
        printf("                                        Please Input Username: \n");
        printf("                                                 ");
        scanf("%s", uss);
        printf ("\n");
        printf("                                        Please Input Password: \n");
        printf("                                                ");
        scanf("%s", pass);
        printf("\n");
        getchar();
        result1 = strcmp (uss, "Rafif");                      //komparasi uss dan pass
        result2 = strcmp (pass, "123456"); 
 
        if (result1 == 0 && result2 == 0){                  //membuat inputan pass dan username harus sama dengan akun kita
            break;
        }else{
                printf("                                           Password Salah...\n");              // jika salah sekali dibawah percobaan ke 3
                printf("                                             Coba lagi\n");
                printf("\n");
                i++;
        }
    }
 
    if (i < 3){                                             //apabila berhasll sebelum percobaan ke 3
    	printf ("\n");
        printf("                                         Anda berhasil login\n");
        printf ("\n");
        printf ("Tekan Enter Untuk Melanjutkan ke Menu...\n");
        getchar();
		system ("cls");
		menu:                                                    //untuk dipanggil goto menu
		getMenu();                                                //memakai fungsi 'get' supaya codingan nya terlihat lebih simple, menampilkan menu utama
		printf ("Apa yang Ingin Anda Lakukan: \n");
		scanf ("%d", &sw);
		system ("cls");
		switch (sw)     {                                          //funsgi switch untuk masalah bercabang yaitu cek akun, mau transfer, exit
		case 4: {
			exit;
			break;
		}
			case 3:{
				goto login;                                       //untuk mengembalikan ke halaman login
				break;
			} 
			case 2:{
        getMenuPilihTransfer();                            
        printf ("\n");                                             //menampilkan layanan transfer yang bisa digunakan
        printf ("Pilih fitur yang ingin anda gunakan: ");
        scanf ("%d", &sw2);
        system ("cls");                                             //membersihkan layar output
        switch(sw2){        
		case 3:{
			goto login;
			break;
		}
		    case 2: {                                                        //case 2 apabila inputan untuk fitur no 2
        		printf ("Pilih Bank penerima dana: \n");
        		char bank [6][20] = {"MANDIRI", "BCA", "BTN", "BRI", "MUAMALAT", "DANAMON"};        //list bank yang saya taro
        		for(x=0;x<6;x++) {																	//membatasi jumlah print = 6
        			printf ("%d. Bank %s\n", x+1,bank[x]);											//print otomatis 1-6
				}
				printf ("Bank Tujuan: ");
				scanf ("%d", &y);
				if (y==1){												//apabila ingin transfer ke bank mandiri
					system ("cls");
					printf("Rekening Tujuan:\n"); 
					scanf("%d", &rek);
					getchar();
					printf("Nama Penerima:\n");
					scanf ("%[^\n]", namatujuan);
					getchar();
					printf("Nominal yang Akan di Transfer:\nRp");
					scanf("%lld", &nominal);
					getchar();
					printf("Berita:\n");
					scanf ("%[^\n]", &berita);
					getchar();
					if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
					printf ("Proses Trasnfer Sedang di Lakukan...\n");
					printf ("Press enter to continue...");
					getchar();
					system ("cls");
					printf ("Validasi\n");
					printf("Nomor Rekening Tujuan:%d\n", rek);
					printf("Nama Rekening Tujuan: %s\n", namatujuan);
					printf("Bank Tujuan: MANDIRI\n");
					printf ("Nominal Rp%lld\n", nominal);
					printf ("Biaya Admin Rp7.500\n");
					printf ("Total: Rp%lld\n", nominal + 7500);
					while (t < 3){
						printf("Masukkan kata sandi transaksi :");
						scanf ("%s", &passT);
						getchar();
						result3 = strcmp (passT, "B1nusian"); 
						if (result3 == 0){
							break;
						}else{
							printf ("\n");
							printf ("Sandi Transaksi Salah\n");
							printf ("Coba Lagi");
							printf ("\n");
							t++;
						}
					}
					if (t<3){
						printf ("Press enter to continue...");
						getchar();
						system ("cls");
						printf ("                          Transaksi Berhasil\n");
					//	waktu *myTime = localtime(&currentTime);
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :MANDIRI\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
						printf("Apakah Anda Ingin Kembali ke Menu?\n");
						printf ("1. Ya\n");
						printf ("2. Tidak\n");
						printf ("Pilih: ");
						scanf ("%s", &ya);
						result4 = strcmp (ya, "1");
						system ("cls");
						if (result4 == 0){
							goto menu;
							break;
							}
							else{
								exit;
					}
					}else{
						printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");
       					printf("Akun anda kami blokir");
					}
										
				}
				
					if (y==2){                                                          //apabila ingin transfer ke bank bca
						system ("cls");
						printf("Rekening Tujuan:\n"); 
						scanf("%d", &rek);
						getchar();
						printf("Nama Penerima:\n");
						scanf ("%[^\n]", namatujuan);
						getchar();
						printf("Nominal yang Akan di Transfer:\nRp");
						scanf("%lld", &nominal);
						getchar();
						printf("Berita:\n");
						scanf ("%[^\n]", &berita);
						getchar();
						if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
						printf ("Proses Trasnfer Sedang di Lakukan...\n");
						printf ("Press enter to continue...");
						getchar();
						system ("cls");
						printf ("Validasi\n");
						printf("Nomor Rekening Tujuan:%d\n", rek);
						printf("Nama Rekening Tujuan: %s\n", namatujuan);
						printf("Bank Tujuan: BCA\n");
						printf ("Nominal %lld\n", nominal);
						printf ("Biaya Admin 7.500\n");
						printf ("Total: %lld\n", nominal + 7500);
						while (t < 3){
							printf("Masukkan kata sandi transaksi :");
							scanf ("%s", &passT);
							getchar();
							result3 = strcmp (passT, "B1nusian"); 
							if (result3 == 0){
								break;
							}else{
								printf ("\n");
								printf ("Sandi Transaksi Salah\n");
								printf ("Coba Lagi");
								printf ("\n\n");
								t++;
							}
						}
						if (t<3){
							printf ("Press enter to continue...");
							getchar();
							system ("cls");
						printf ("                          Transaksi Berhasil\n");
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :BCA\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
							printf("Apakah Anda Ingin Kembali ke Menu?\n");
							printf ("1. Ya\n");
							printf ("2. Tidak\n");
							printf ("Pilih: ");
							scanf ("%s", &ya);
							result4 = strcmp (ya, "1");
							system ("cls");
							if (result4 == 0){
								goto menu;
								break;
							}
							else{
								exit;
						}
						}else {
							printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");
       						printf("Akun anda kami blokir");
						}
					}
					if (y==3){                                                   //apabila ingin transfer ke bank BTN
						system ("cls");
						printf("Rekening Tujuan:\n"); 
						scanf("%d", &rek);
						getchar();
						printf("Nama Penerima:\n");
						scanf ("%[^\n]", namatujuan);
						getchar();
						printf("Nominal yang Akan di Transfer:\nRp");
						scanf("%lld", &nominal);
						getchar();
						printf("Berita:\n");
						scanf ("%[^\n]", &berita);
						getchar();
						if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
						printf ("Proses Trasnfer Sedang di Lakukan...\n");
						printf ("Press enter to continue...");
						getchar();
						system ("cls");
						printf ("Validasi\n");
						printf("Nomor Rekening Tujuan:%d\n", rek);
						printf("Nama Rekening Tujuan: %s\n", namatujuan);
						printf("Bank Tujuan: BTN\n");
						printf ("Nominal Rp%lld\n", nominal);
						printf ("Biaya Admin Rp7.500\n");
						printf ("Total: Rp%lld\n", nominal + 7500);
						while (t < 3){
							printf("Masukkan kata sandi transaksi :");
							scanf ("%s", &passT);
							getchar();
							result3 = strcmp (passT, "B1nusian"); 
							if (result3 == 0){
								break;
							}else{
								printf ("\n");
								printf ("Sandi Transaksi Salah\n");
								printf ("Coba Lagi");
								printf ("\n\n");
								t++;
							}
						}
						if (t<3){
							printf ("Press enter to continue...");
							getchar();
							system ("cls");
						printf ("                          Transaksi Berhasil\n");
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :BTN\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
							printf("Apakah Anda Ingin Kembali ke Menu?\n");
							printf ("1. Ya\n");
							printf ("2. Tidak\n");
							printf ("Pilih: ");
							scanf ("%s", &ya);
							result4 = strcmp (ya, "1");
							system ("cls");
							if (result4 == 0){
								goto menu;
								break;
							}
							else{
								exit;
					}
						}else {
							printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");
       						printf("Akun anda kami blokir");
						}
					}
					if (y==4){                                                                //apabila ingin transfer ke bank bri
						system ("cls");
						printf("Rekening Tujuan:\n"); 
						scanf("%d", &rek);
						getchar();
						printf("Nama Penerima:\n");
						scanf ("%[^\n]", namatujuan);
						getchar();
						printf("Nominal yang Akan di Transfer:\nRp");
						scanf("%lld", &nominal);
						getchar();
						printf("Berita:\n");
						scanf ("%[^\n]", &berita);
						getchar();
						if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
						printf ("Proses Trasnfer Sedang di Lakukan...\n");
						printf ("Press enter to continue...");
						getchar();
						system ("cls");
						printf ("Validasi\n");
						printf("Nomor Rekening Tujuan:%d\n", rek);
						printf("Nama Rekening Tujuan: %s\n", namatujuan);
						printf("Bank Tujuan: BRI\n");
						printf ("Nominal Rp%lld\n", nominal);
						printf ("Biaya Admin Rp7.500\n");
						printf ("Total: Rp%lld\n", nominal + 7500);
						while (t < 3){
							printf("Masukkan kata sandi transaksi :");
							scanf ("%s", &passT);
							getchar();
							result3 = strcmp (passT, "B1nusian"); 
							if (result3 == 0){
								break;
							}else{
								printf ("\n");
								printf ("Sandi Transaksi Salah\n");
								printf ("Coba Lagi");
								printf ("\n\n");
								t++;
							}
						}
						if (t<3){
							printf ("Press enter to continue...");
							getchar();
							system ("cls");
						printf ("                          Transaksi Berhasil\n");
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :BRI\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
							printf("Apakah Anda Ingin Kembali ke Menu?\n");
							printf ("1. Ya\n");
							printf ("2. Tidak\n");
							printf ("Pilih: ");
							scanf ("%s", &ya);
							result4 = strcmp (ya, "1");
							system ("cls");
							if (result4 == 0){
								goto menu;
								break;
							}
							else{
								exit;
						}
						}else {
							printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");
       						printf("Akun anda kami blokir");
						}
					}
					if (y==5){                                                            //apabila ingin transfer ke bank muamalat
						system ("cls");
						printf("Rekening Tujuan:\n"); 
						scanf("%d", &rek);
						getchar();
						printf("Nama Penerima:\n");
						scanf ("%[^\n]", namatujuan);
						getchar();
						printf("Nominal yang Akan di Transfer:\nRp");
						scanf("%lld", &nominal);
						getchar();
						printf("Berita:\n");
						scanf ("%[^\n]", &berita);
						getchar();
						if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
						printf ("Proses Trasnfer Sedang di Lakukan...\n");
						printf ("Press enter to continue...");
						getchar();
						system ("cls");
						printf ("Validasi\n");
						printf("Nomor Rekening Tujuan:%d\n", rek);
						printf("Nama Rekening Tujuan: %s\n", namatujuan);
						printf("Bank Tujuan: MUAMALAT\n");
						printf ("Nominal Rpll%d\n", nominal);
						printf ("Biaya Admin Rp7.500\n");
						printf ("Total: Rpll%d\n", nominal + 7500);
						while (t < 3){
							printf("Masukkan kata sandi transaksi :");
							scanf ("%s", &passT);
							getchar();
							result3 = strcmp (passT, "B1nusian"); 
							if (result3 == 0){
								break;
							}else{
								printf ("\n");
								printf ("Sandi Transaksi Salah\n");
								printf ("Coba Lagi");
								printf ("\n\n");
								t++;
							}
						}
						if (t<3){
							printf ("Press enter to continue...");
							getchar();
							system ("cls");
						printf ("                          Transaksi Berhasil\n");
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :MUAMALAT\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
							printf("Apakah Anda Ingin Kembali ke Menu?\n");
							printf ("1. Ya\n");
							printf ("2. Tidak\n");
							printf ("Pilih: ");
							scanf ("%s", &ya);
							result4 = strcmp (ya, "1");
							system ("cls");
							if (result4 == 0){
							goto menu;
							break;
						}
							else{
								exit;
					}
						}else {
							printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");
       						printf("Akun anda kami blokir");
						}
					}
					if (y==6){                                                            //apabila ingin transfer ke bank danamon
						system ("cls");
						printf("Rekening Tujuan:\n"); 
						scanf("%d", &rek);
						getchar();
						printf("Nama Penerima:\n");
						scanf ("%[^\n]", namatujuan);
						getchar();
						printf("Nominal yang Akan di Transfer: \nRp");
						scanf("%lld", &nominal);
						getchar();
						printf("Berita:\n");
						scanf ("%[^\n]", &berita);
						getchar();
						if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
						printf ("Proses Trasnfer Sedang di Lakukan...\n");
						printf ("Press enter to continue...");
						getchar();
						system ("cls");
						printf ("Validasi\n");
						printf("Nomor Rekening Tujuan:%d\n", rek);
						printf("Nama Rekening Tujuan: %s\n", namatujuan);
						printf("Bank Tujuan: DANAMON\n");
						printf ("Nominal Rp%lld\n", nominal);
						printf ("Biaya Admin Rp7.500\n");
						printf ("Total: %lld\n", nominal + 7500);
						while (t < 3){
							printf("Masukkan kata sandi transaksi :");
							scanf ("%s", &passT);
							getchar();
							result3 = strcmp (passT, "B1nusian"); 
							if (result3 == 0){
								break;
							}else{
								printf ("\n");
								printf ("Sandi Transaksi Salah\n");
								printf ("Coba Lagi");
								printf ("\n\n");
								t++;
							}
						}
						if (t<3){
							printf ("Press enter to continue...");
							getchar();
							system ("cls");
						printf ("                          Transaksi Berhasil\n");
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :DANAMON\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
							printf("Apakah Anda Ingin Kembali ke Menu?\n");
							printf ("1. Ya\n");
							printf ("2. Tidak\n");
							printf ("Pilih: ");
							scanf ("%s", &ya);
							result4 = strcmp (ya, "1");
							system ("cls");
							if (result4 == 0){
								goto menu;
								break;
							}
							else{
								exit;
						}
						}else {
							printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");
       						printf("Maaf Akun Anda Kami Blokir");
						}
					}
					
				
				break;
			}
			case 1: {                                                 //case 1 untuk apabila user menginput angka 1 dmn user ingin transfer ke sesama bank
				printf("Rekening Tujuan:\n"); 
				scanf("%d", &rek);
				getchar();
				printf("Nama Penerima:\n");
				scanf ("%[^\n]", namatujuan);
				getchar();
				printf("Nominal yang Akan di Transfer: \nRp");
				scanf("%lld", &nominal);
				getchar();
				printf("Berita:\n");
				scanf ("%[^\n]", &berita);
				getchar();
					if (nominal > 1000000000){
						printf ("Maaf Saldo Anda Tidak Mencukupi\n");
						printf ("Tekan Enter Untuk Kembali ke Halaman menu \n");
						getchar();
						system ("cls");
						goto menu;
						break;
					}
				printf ("Proses Trasnfer Sedang di Lakukan...\n");
				printf ("Press enter to continue...");
				getchar();
				system("cls"); 
				printf ("Validasi\n");
				printf("Nomor Rekening Tujuan:%d\n", rek);
				printf("Nama Rekening Tujuan: %s\n", namatujuan);
				printf("Bank Tujuan: BNI\n");
				printf ("Nominal Rp%lld\n", nominal);
				printf ("Biaya Admin Rp.0\n");
				printf ("Total: %lld\n", nominal);
				for (i=0;i<3;i++){                                                               //membatasi pengulangan 
					printf("Masukkan kata sandi transaksi :");
					scanf ("%s", &passT);
					getchar();
					if ((strcmp(passT,"B1nusian"))==0){                                          //menghentikan pengulangan
						break;
					}else {                                                                      //password masih salah dibawah 3 kali
						printf ("\n");
						printf ("Maaf Sandi Transaksi Salah\n");
						printf ("Coba Lagi");
						printf ("\n\n");
						t = t+1;
					}
				}
				if (t<3){                                                                       //password sudah benar dibawah percobaan ke 3
					printf ("Press enter to continue...");
					getchar();
					system ("cls");
						printf ("                          Transaksi Berhasil\n");
						printf ("Tanggal Transaksi                                    :%d-%d-%d-n", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year +1900 );	
		                printf ("Waktu Transaksi                                      :%d:%d:%d\n WIB", myTime->tm_hour, myTime->tm_min,myTime->tm_sec);
						printf("Nomor Rekening Tujuan                                :%d\n", rek);
						printf("Nama Rekening Tujuan                                 :%s\n", namatujuan);
						printf("Bank Tujuan                                          :BNI\n");
						printf("Nama Pengirim                                        :Muhammad Rafif\n");
						printf ("Nomor Rekening Pengirim                              :2440057741\n");
						printf ("Nominal                                              :%s%lld\n",rp, nominal);
						printf ("Biaya Admin                                          :Rp7.500\n");
						printf ("Total                                                :Rp%lld\n", nominal + 7500);
						printf ("Berita                                               :%s\n", berita);
					printf("Apakah Anda Ingin Kembali ke Menu?\n");
					printf ("1. Ya\n");
					printf ("2. Tidak\n");
					printf ("Pilih: ");
					scanf ("%s", &ya);
					result4 = strcmp (ya, "1");
					system ("cls");
					if (result4 == 0){
					goto menu;
					break;
					}
					else{
						exit;
					}
				} else{                                                                          //sudah 3 kali salah
					printf ("Maaf Anda sudah mencoba sebanyak 3 kali\n");
					printf ("Maaf Akun Anda Kami Blokir");
				}
				
				break;
		}
				
		}
					break;
			}  
			case 1:{
				getInformasiAkun();                                                         //memanggil tabel informasi akun dengan get
				printf("Apakah Anda Ingin Kembali ke Menu?\n");
				printf ("1. Ya\n");
				printf ("2. Tidak\n");
				printf ("Pilih: ");
				scanf ("%s", &ya);
				result4 = strcmp (ya, "1");                                                  //apabila ya (1) maka akan kembali ke halaman menu
				system ("cls");
				if (result4 == 0){                                                            
					goto menu;                                                              //mengembalikkan output kepada menu utama
					break;
				}
				else{
					exit;
				}
				break;
			}
			 
		}                                              
		
        
    }else{
        printf("Maaf Anda sudah mencoba sebanyak 3 kali\n");                        //sudah 3 kali salah
        printf("Akun anda kami blokir");
    }
 
    return 0;
}

void getMenu(){ // Menu Utama
	printf ("===========================================         MENU UTAMA         ================================================\n");
	printf ("\n");
	printf("1. Cek Informasi Akun\n");
	printf("2. Transfer Uang\n");
	printf("3. Kembali ke Halaman Login\n");
	printf("4. Keluar dari Layanan BNI M - Banking\n");
	printf ("\n");
	printf ("=======================================================================================================================\n");
}

void getInformasiAkun(){ //Informasi Akun
	printf ("============================================        INFORMASI AKUN       ===============================================\n");
	printf ("\n");
	printf("Nama Akun: Muhammad Rafif\n");
	printf("No Rekening: 2440057741\n");
	printf("Saldo: 10.000.000.000\n");
	printf ("\n");
	printf ("=======================================================================================================================\n");
}	
void getMenuPilihTransfer(){ // Menu Pilihan Transfer 
	printf ("===========================================         MENU TRANSFER       ===============================================\n");
	printf ("\n");
	printf("1. Transfer Ke Sesama Rekening\n");
	printf("2. Transfer ke Rekening Bank Lain\n");
	printf("3. Kembali ke Halaman Login\n");
	printf ("\n");
	printf ("=======================================================================================================================\n");
}
