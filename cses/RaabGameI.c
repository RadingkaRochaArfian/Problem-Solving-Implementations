#include <stdio.h>
int isValid(int n, int a, int b) {
  if (a + b > n)
    return 0;
  if (a > 0 && b == 0)
    return 0;
  if (b > 0 && a == 0)
    return 0;
  return 1;
}
void printRest(int n, int a, int b) {
  for (int i = a + 1; i <= a + b; i++) {
    printf("%d ", i);
  }
  for (int i = 1; i <= a; i++) {
    printf("%d", i);
    if (i < a)
      printf(" ");
  }
  int ties = n - (a + b);
  for (int i = ties; i > 0; i--) {
    printf(" %d", n - i + 1);
  }
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (!isValid(n, a, b)) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      printf("%d", i);
      if (i < n)
        printf(" ");
    }
    printf("\n");
    printRest(n, a, b);
  }
}