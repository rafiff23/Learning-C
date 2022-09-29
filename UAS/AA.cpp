#include<stdio.h>
#include<string.h>

struct person {
	int idnumber;
	char name[100];
	int wide;
	int feet;
	double sz;
};

void merge( struct person data[], int left, int middle, int right, int status ) {
	int d1 = middle-left+1;
	int d2 = right-middle;
	struct person left_array[d1];
	struct person right_array[d2];
	for ( int i = 0 ; i < d1 ; i++ ) {
		left_array[i] = data[left+i];
	}
	for ( int j = 0 ; j < d2 ; j++ ) {
		right_array[j] = data[middle+1+j];
	}
	int k = 0, l = 0, m = left;
	if ( status == 0 ) {
		while ( k < d1 && l < d2 ) {
			if ( left_array[k].idnumber <= right_array[l].idnumber ) {
				data[m] = left_array[k];
				k++;
			} 
			else {
				data[m] = right_array[l];
				l++;
			}
			m++;
		}
	} 
	else {
		//for {
		while ( k < d1 && l < d2 ) {
			if ( left_array[k].sz >= right_array[l].sz ) {
			data[m] = left_array[k];
			k++;
			} 
			else {
				data[m] = right_array[l];
				l++;
			}
			m++;
		}
	//}
	}
	while ( k < d1 ) {
		data[m] = left_array[k];
		m++;
		k++;
	}
	while ( l < d2 ) {
		//while{
		data[m] = right_array[l];
		m++;
		l++;
	}
}
// }
void mgsort( struct person data[], int left, int right, int status ) {
	if ( left >= right ) {
		return;
	}
	int middle = left + (right - left) / 2;
	mgsort(data, left, middle, status);
	mgsort(data, middle+1, right, status);
	merge(data, left, middle, right, status);
}

int main() {
	int t, u, i;
	scanf("%d", &t);
	getchar();
	struct person data[t];
	for (i = 0 ; i < t ; i++ ) {
		scanf("%d,%[^,],%d %d", &data[i].idnumber, data[i].name, &data[i].feet, &data[i].wide );
		getchar();
		data[i].sz = ((double) data[i].feet * 12 * 2.54 ) + ((double) data[i].wide * 2.54);
	}
	mgsort(data, 0, t-1, 0);
	mgsort(data, 0, t-1, 1);
	scanf("%d", &u);
	getchar();
		for (i = 1 ; i <= u ; i++ ) {
			int query;
			scanf("%d", &query);
			getchar();
			printf("Q%d:\n", i);
			int flag = 0;
			for ( int j = 0 ; j < t ; j++ ) {
				if ( data[j].sz <= query ) {
					printf("%d %s %.2lf\n", data[j].idnumber, data[j].name, data[j].sz);
					flag++;
				}
			}
			if (flag == 0 ) {
				printf("-1\n");
			}
		}
		return 0;
}
