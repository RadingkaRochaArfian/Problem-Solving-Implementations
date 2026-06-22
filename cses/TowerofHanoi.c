#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
  int *data;
  int count;
} innerlist;
 
typedef struct {
  innerlist **langkah;
  int count;
} nestedlist;
 
void tambahLangkah(nestedlist *ans, int base, int to) {
  innerlist *langkah = malloc(sizeof(innerlist));
  langkah->data = malloc(sizeof(int) * 2);
  langkah->data[0] = base;
  langkah->data[1] = to;
  langkah->count = 2;
  ans->langkah = realloc(ans->langkah, sizeof(innerlist *) * (ans->count + 1));
  ans->langkah[ans->count] = langkah;
  ans->count++;
  return;
}
 
void hanoi(int left, int mid, int right, nestedlist *ans, int n) {
  if (n == 1) {
    tambahLangkah(ans, left, right);
    return;
  }
  hanoi(left, right, mid, ans, n - 1);
  tambahLangkah(ans, left, right);
  hanoi(mid, left, right, ans, n - 1);
}
void solve(int n) {
  int left = 1, mid = 2, right = 3;
  nestedlist *ans = malloc(sizeof(nestedlist));
  ans->langkah = NULL;
  ans->count = 0;
  hanoi(left, mid, right, ans, n);
  for (int i = 0; i < ans->count; i++) {
    printf("%d %d\n", ans->langkah[i]->data[0], ans->langkah[i]->data[1]);
  }
  for (int i = 0; i < ans->count; i++) {
    free(ans->langkah[i]->data);
    free(ans->langkah[i]);
  }
  free(ans->langkah);
  free(ans);
}
 
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", (1 << n) - 1);
  solve(n);
  return 0;
}