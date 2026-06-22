#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
  char **data;
  int count;
} arraylist;
 
arraylist *solve(int n) {
  if (n == 1) {
    arraylist *ret = malloc(sizeof(arraylist));
    ret->count = 2;
    ret->data = malloc(sizeof(char *) * 2);
    ret->data[0] = malloc(2);
    ret->data[1] = malloc(2);
    strcpy(ret->data[0], "0");
    strcpy(ret->data[1], "1");
    return ret;
  }
  arraylist *prev = solve(n - 1);
  arraylist *curr = malloc(sizeof(arraylist));
  curr->count = prev->count * 2;
  curr->data = malloc(sizeof(char *) * curr->count);
  for (int i = 0; i < prev->count; i++) {
    curr->data[i] = malloc(n + 1);
    sprintf(curr->data[i], "0%s", prev->data[i]);
  }
  for (int i = 0; i < prev->count; i++) {
    curr->data[prev->count + i] = malloc(n + 1);
    sprintf(curr->data[prev->count + i], "1%s",
            prev->data[prev->count - 1 - i]);
  }
  for (int i = 0; i < prev->count; i++) {
    free(prev->data[i]);
  }
  free(prev->data);
  free(prev);
  return curr;
}
 
int main() {
  int n;
  scanf("%d", &n);
  arraylist *list = solve(n);
  for (int i = 0; i < list->count; i++) {
    printf("%s\n", list->data[i]);
    free(list->data[i]);
  }
  free(list->data);
  free(list);
  return 0;
}