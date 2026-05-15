#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Project dari mahasiswa Jurusan Data Science =
// 1. Kelvin Alexander Bong - 2602101823
// 2. Keitaro Alexander Herman - 2602227775
// 3. Justinus Natanael Bensohur - 2602094004
struct staff{
	char nama[30];
	long long int harga;
	int stock;
	char kode[100];
	int no;
}gudang[1000];

struct kasir{
	char nama[30];	// nama kasir
	char kodetrx[100];	// kode transaksi
	char kode[100];	// kode produk (bukan kode transaksi)
	long int jumlah;	// jumlah pembelian
	long int jmltrx;	// jumlah total transaksi
}kasir[1000];


int main(){
	printf("Project tugas mahasiswa jurusan Data Science=\n1. Kelvin Alexander Bong - 2602101823\n2. Keitaro Alexander Herman - 2602227775\n3. Justinus Natanael Bensohur - 2602094004\n\n");
    struct staff gudang[1000];
	int pilihan,staff,urut=0,update,stok2,kedua,urut1=0,tanda,tanda1,urut11=0;
	char nama1[25];
	char stok[100];
	int jmltrx;
	int flag;
	char jumlahp[100];
	char tambah;
	char intemp[100];
	char produk[1000];
	utama:
		printf("Menu Utama\n1. Staff Gudang\n2. Kasir\n3. Keluar\n");
		do{
		printf("Masukan pilihan: ");
		scanf("%d",&pilihan);
		getchar();
		}while(pilihan<1 || pilihan>3);
	
	switch (pilihan){
		case 1:
			menu:
				printf("\nMenu Staff Gudang\n1. Menambah Barang\n2. Lihat Barang\n3. Update Stok\n4. Kembali Menu Utama\n");
				do{
					printf("Masukan pilihan: ");
					scanf("%d",&staff);
					getchar();
				}while(staff<1 || staff>4);
			printf("\n");
			switch (staff){
				case 1:
					do{
						printf("Nama produk: ");
						scanf("%[^\n]", nama1);
						getchar();
					}while(strlen(nama1)<5 || strlen(nama1)>20);
					sprintf(gudang[urut].nama, nama1);
					do{
						printf("Harga: ");
						scanf("%lld",&gudang[urut].harga);
						getchar();
					}while(gudang[urut].harga<1000 || gudang[urut].harga>1000000);
					
					do{
						printf("Stock: ");
						scanf("%s",intemp);
						getchar();
						flag = 1;	// 1 -> semua karakter sejauh ini adalah angka; 0 -> bukan 1
						int i=0;
						while(intemp[i] != '\0' && (flag == 1)){
							if (!(isdigit(intemp[i]))){
								flag = 0;
							}
							i++;
						}
						// intemp[i] == '\0' ATAU flag != 1
						if(flag == 0){
							printf("Pastikan input hanya berupa angka!\n");
						}
						else{
							gudang[urut].stock = 0;
							i = 0;
							while (intemp[i] != '\0')
							{
								gudang[urut].stock *= 10;
								gudang[urut].stock += (intemp[i] - '0');	// ubah digit intemp[i] ke int
								i++;
							}
							// printf("test stock %d\n", gudang[urut].stock);
						}
					}while(flag == 0);
					// flag != 0 -> input semua berupa angka
					gudang[urut].no = urut+1;
					sprintf(gudang[urut].kode,"BIC%d",urut+1);
					printf("Barang berhasil diinput dengan kode produk %s\n",gudang[urut].kode);
				    urut++;
				    goto menu;
				    break;
				case 2:
					if(urut==0){
						printf("Data barang kosong\n");
						goto menu;}
					else{
						for(int d=0;d<89;d++){
							printf("-");
						}
						printf("\n");
						printf("%-5s | %-15s | %-25s | %-15s | %-15s |\n","No","Kode Produk","Nama Produk","Harga Produk","Stock");
						for(int f=0;f<89;f++){
							printf("-");
						}
						printf("\n");
						for(int i=0;i<urut;i++){
							printf("%-5d | %-15s | %-25s | %-15d | %-15d |\n",gudang[i].no,gudang[i].kode,gudang[i].nama,gudang[i].harga,gudang[i].stock);
							for(int g=0;g<89;g++){
								printf("-");
							}
							printf("\n");
						}
					}
					goto menu;
					break;
				case 3:
					tanda=0;
					if(urut==0){
						printf("Data barang kosong\n");
						goto menu;
					}
					else{
						for(int b=0;b<89;b++){
							printf("-");
						}
						printf("\n");
						printf("%-5s | %-15s | %-25s | %-15s | %-15s |\n","No","Kode Produk","Nama Produk","Harga Produk","Stock");
						for(int e=0;e<89;e++){
							printf("-");
						}
						printf("\n");
						for(int i=0;i<urut;i++){
							printf("%-5d | %-15s | %-25s | %-15d | %-15d |\n",gudang[i].no,gudang[i].kode,gudang[i].nama,gudang[i].harga,gudang[i].stock);
							for(int c=0;c<89;c++){
							printf("-");
							}
							printf("\n");
						}
						do{
						printf("No barang yang ingin diupdate: ");
						scanf("%d",&update);
						getchar();
						for(int i=0;i<urut;i++){
							if(update==gudang[i].no){
								tanda++;
							}
						}}while(tanda==0);
						
						do{
							printf("Stock Update: ");
							scanf("%s",stok);
							getchar();
							flag = 1;
							int z = 0;
							while(stok[z] != '\0' && (flag ==1)){
								if(!(isdigit(stok[z]))){
									flag = 0;
								}
								z++;
							}
							if(flag== 0){
								printf("Pastikan input hanya berupa angka!\n");
							}
							else{
								stok2 = 0;
								z = 0;
								while(stok[z] != '\0'){
									stok2 *= 10;
									stok2 += (stok[z] - '0');
									z++;
								}
							}
						}while(flag == 0);
						gudang[update-1].stock= stok2;
						printf("Stok Barang %s Berhasil di Update\n",gudang[update-1].nama);
						}
					goto menu;
					break;
				case 4:
					goto utama;
					break;
		}
		// kasir
		case 2:
			menu2:
				printf("\n1. Menambah Transaksi\n2. Menampilkan List Transaksi\n3. Kembali Menu Utama\n");
					do{
					printf("Masukan Pilihan: ");
					scanf("%d",&kedua);
					}while(kedua<0 || kedua>3);
			switch(kedua){
				case 1:
					jmltrx = 0; // total pembayaran transaksi
					printf("Nama kasir: ");
					do{
						scanf("%s",&kasir[urut1].nama);
					}while(strlen(kasir[urut1].nama)<5 && strlen(kasir[urut1].nama)>20);

					// tambah produk dalam transaksi
					do{
						printf("Kode Produk: ");
						scanf("%s",&kasir[urut1].kode);
						getchar();
						for(int i=0;i<urut;i++){
							if(strcmp(kasir[urut1].kode,gudang[i].kode)==0){
								tanda1=i;
								}
						}
						}while(strcmp(kasir[urut1].kode,gudang[tanda1].kode)==1);
					
					do{
						do{
							printf("Jumlah pembelian: ");
							scanf("%s",&jumlahp);
							getchar();
							flag = 1; 
							int r = 0;
							while(jumlahp[r] != '\0' && (flag ==1)){
								if(!(isdigit(jumlahp[r]))){
									flag = 0;
								}
								r++;
							}
							if(flag == 0){
								printf("Pastikan input hanya angka!\n");
							}
							else{
								kasir[urut1].jumlah = 0;
								r = 0;
								while(jumlahp[r] != '\0'){
									kasir[urut1].jumlah *= 10;
									kasir[urut1].jumlah += (jumlahp[r] - '0');
									r++;
								}
							}
						}while(flag == 0);
					}while(kasir[urut1].jumlah>gudang[tanda1].stock);

					gudang[tanda1].stock-=kasir[urut1].jumlah;

					jmltrx += kasir[urut1].jumlah * gudang[tanda1].harga;
					kasir[urut1].jmltrx = -1;
					urut1++;
					urut11++;
					sprintf(kasir[urut1-1].kodetrx, "TK%d",urut11);
					sprintf(kasir[urut11-1].kode, "TK%d",urut11);
					// selesai tambah produk dalam transaksi

					while(1){
						opsipilihan:
						printf("Apakah ingin menambahkan produk pada transaksi: ");
						scanf("%s",&tambah);
						getchar();
						if(tambah=='Y'){
							sprintf(kasir[urut1].nama, "");
							sprintf(kasir[urut1].kodetrx, "");
							// selama nama dan kodetrx == "-", berarti transaksi merupakan transaksi yang sama dengan transaksi sebelum-sebelumnya
							// hingga transaksi dengan kodetrx yang bukan "-" pertama (inklusif). Contoh:
							// transaksi[i].kode != "-"
							// transaksi[i+1].kode == "-", transaksi[i+2].kode == "-", ..., transaksi[i+n].kode == "-"
							// transaksi[i..i+n] adalah transaksi yang sama; kode dan nama kasirnya sama, namun masing2
							// menyatakan produk yang dibeli pada transaksi tersebut.

							do{
								printf("Kode Produk: ");
								scanf("%s",&kasir[urut1].kode);
								getchar();
								for(int i=0;i<urut;i++){
									if(strcmp(kasir[urut1].kode,gudang[i].kode)==0){
										tanda1=i;
									}
								}
							}while(strcmp(kasir[urut1].kode,gudang[tanda1].kode)==1);
						
							do{
								do{
									printf("Jumlah pembelian: ");
									scanf("%s",&jumlahp);
									getchar();
									flag = 1; 
									int r = 0;
									while(jumlahp[r] != '\0' && (flag ==1)){
										if(!(isdigit(jumlahp[r]))){
											flag = 0;
										}
										r++;
									}
									if(flag == 0){
										printf("Pastikan input hanya angka!\n");
									}
									else{
										kasir[urut1].jumlah = 0;
										r = 0;
										while(jumlahp[r] != '\0'){
											kasir[urut1].jumlah *= 10;
											kasir[urut1].jumlah += (jumlahp[r] - '0');
											r++;
										}
									}
								}while(flag == 0);
							}while(kasir[urut1].jumlah>gudang[tanda1].stock);

							gudang[tanda1].stock -= kasir[urut1].jumlah;

							jmltrx += kasir[urut1].jumlah * gudang[tanda1].harga;
							kasir[urut1].jmltrx = -1;
							urut1++;
						}
						else if(tambah=='N'){
							kasir[urut1-1].jmltrx = jmltrx;
							printf("Total Transaksi %s adalah Rp. %d",kasir[urut11-1].kode, jmltrx);
							break;
						}
						else {
							goto opsipilihan;
							break;
						}
					}
					goto menu2;
					break;
					
				case 2:
					if(urut1 == 0){
						printf("Data barang kosong");
						goto menu2;
					}
					else{
						for(int t=0;t<120;t++){
							printf("-");
						}
						printf("\n");
						printf("%-3s | %-14s | %-20s | %-17s | %-52s |\n","No","Kode Transaksi","Nama Kasir","Total","Detail Pembelian");
						for(int i=0;i<120;i++){
							printf("-");
						}
						printf("\n");
						int x = 0 ; // transaksi ke berapa
						int y;		// urutan produk ke berapa
						char nom[5];	// nomor produk
						char totalprint[15];	// total harga
							for(int i = 0;i<urut1;i++){
								for(int j = 0; j<urut; j++){
									if(strcmp(kasir[i].kode,gudang[j].kode) == 0){
										tanda1 = j;
										break;
									}
								}

								if(kasir[i].kodetrx[0] != '\0'){
									x += 1;
									y = 1;
									sprintf(nom, "%d", x);
								} else {
									sprintf(nom, "");
								}

								if (kasir[i].jmltrx != -1){
									sprintf(totalprint, "Rp.%d", kasir[i].jmltrx);
								}
								else {
									sprintf(totalprint, "");
								}

								// produk adalah elemen detail pembelian
								sprintf(produk, "%d.%-3s - %s - %d pcs - Rp. %d", y, gudang[tanda1].kode, gudang[tanda1].nama, kasir[i].jumlah, gudang[tanda1].harga);
								y++;
								printf("%-3s | %-14s | %-20s | %-17s | %-52s |\n", nom, kasir[i].kodetrx, kasir[i].nama, totalprint, produk);
								for(int a=0;a<120;a++){
									printf("-");
								}
								printf("\n");
							}
					}
					goto menu2;
					break;

				case 3:
					goto utama;
					break;
			}
		case 3:
			break;
	}
	return 0;
}

