#include <stdio.h>
#include <string.h>

struct pelanggan{
 char id[10];
 char nama[25];
 int umur;
 double saldo;
}; 
pelanggan record[50005];

int binarySearch (char id[], int startIdx, int endIdx) {
 	if (startIdx > endIdx){
  		return -1;
 	}
 
 	int midIdx = (startIdx + endIdx) / 2;
 	pelanggan curr = record[midIdx];
 	int compare = strcmp(id, curr.id);
 
 	int sama = compare == 0;
 	int kurangdari = compare < 0;
 	int besardari = compare > 0;
 
 	if (sama){
  		return midIdx;
 	}
 	if (kurangdari){
  		return binarySearch(id, startIdx, midIdx - 1);
 	}
 	if (besardari){
  		return binarySearch(id, midIdx + 1, endIdx);
 	}
}

void merge_by_title(int idx_left1,int idx_right1,int idx_left2,int idx_right2){
    int n_1 = idx_right1-idx_left1+1;
    int n_2 = idx_right2-idx_left2+1;
    
    pelanggan pertama[n_1];
    pelanggan kedua[n_2];
    for(int i = 0; i < n_1; i++){
        pertama[i] = record[idx_left1+i];
    }
    for(int i = 0; i < n_2; i++){
        kedua[i] = record[idx_left2+i];
    }
    int k1 = 0;
    int k2 = 0;
    int k = idx_left1;
    while(k1 < n_1 && k2 <n_2){
        if(strcmp(pertama[k1].id,kedua[k2].id)<0){
            record[k] = pertama[k1];
            k1++;
            k++;
        } else {
            record[k] = kedua[k2];
            k2++;
            k++;
        }
    }
    while(k1 < n_1){
        record[k] = pertama[k1];
        k1++;
        k++;
    }
    while(k2 < n_2){
        record[k] = kedua[k2];
        k2++;
        k++;
    }
}

void sort_by_title(int idx_kiri,int idx_kanan){
    if(idx_kiri >= idx_kanan) 
	return;
    
    int idx_tengah = (idx_kiri+idx_kanan)/2;
    
    sort_by_title(idx_kiri,idx_tengah);
    sort_by_title(idx_tengah+1,idx_kanan);
    
    merge_by_title(idx_kiri,idx_tengah,idx_tengah+1,idx_kanan);
}

int main()
{
 	int n;
 	scanf("%d",&n); getchar();
 
 	for(int i = 0; i < n; i++){
  		scanf("%[^,],%[^,],%d,%lf",&record[i].id,&record[i].nama,&record[i].umur,&record[i].saldo); getchar();
	}
 
 	sort_by_title(0,n-1);

 	int nCase;
 	scanf("%d",&nCase);
 	for(int i = 0; i < nCase; i++){
  		char id[21];
  		scanf("%s%*c", id);
  		int idx = binarySearch(id, 0, n-1);
  		int notFound = idx == -1;
  		if (notFound) {
   			printf("-1\n");
  		} else {
   			printf("%s %d %.2lf\n",record[idx].nama,record[idx].umur,record[idx].saldo);
  		}
	}  

    return 0;
}
