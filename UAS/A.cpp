#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_SIZE 20
#define MAX_N 50000

typedef struct Record record_t;
struct Record {
  int ID;
  char name[MAX_NAME_SIZE];
  int foot;
  int inch;
  float cm;
};

int compar(const void *left_ptr, const void *right_ptr) {
  const record_t left = * (record_t *) left_ptr;
  const record_t right = * (record_t *) right_ptr;
  if(left.foot < right.foot) {
    return 1;
  } else if(left.foot == right.foot) {
    if(left.inch < right.inch) {
      return 1;
    } else if(left.inch == right.inch) {
      return left.ID - right.ID;
    }
  }
  return -1;
}

int find(const record_t *records,
         const int left,
         const int right,
         const float query) {
  if(left > right) {
    return -1;
  }

  if(left == right) {

    if(records[left].cm <= query) {
      return left;
    }
    return -1;
  }
  const int mid = left + (right - left) / 2;

  if(records[mid].cm > query) {
    return find(records, mid + 1, right, query);
  }
  return find(records, left, mid, query);
}
int main() {
  int N;
  scanf("%d\n", &N);
  record_t records[MAX_N];
  for(int i = 0; i < N; ++i) {
    scanf("%d,%[^,],%d %d\n",
          &records[i].ID,
          records[i].name,
          &records[i].foot,
          &records[i].inch);
    records[i].cm = records[i].foot * 12 * 2.54 +
                    records[i].inch * 2.54;
  }
  qsort(records, N, sizeof(record_t), compar);
  int M;
  scanf("%d\n", &M);
  int query;
  for(int i = 1; i <= M; ++i) {
    scanf("%d\n", &query);
    printf("Q%d:\n", i);
    int index = find(records, 0, N - 1, query);
    if(index == -1) {
      puts("-1");
      continue;
    }
    while(index < N) {
      printf("%d %s %.2f\n",
             records[index].ID,
             records[index].name,
             records[index].cm);
      ++index;
    }
  }
  return 0;
}
