#include <stdio.h>
#include <string.h>
int isPalindrome(char sub[], int n) {
  for (int i = 0; i < (n / 2); i++) {
    if (sub[i] != sub[n - 1 - i]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  char s[11];
  char sub[11];
  char mx[11] = "";
  scanf("%s", s);
  int n = strlen(s);
  for (int mask = 1; mask < (1 << n); mask++) {
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sub[idx++] = s[i];
      }
    }
    sub[idx] = '\0';
    if (isPalindrome(sub, idx)) {
      if (strcmp(sub, mx) > 0) {
        strcpy(mx, sub);
      }
    }
  }
  printf("%s\n", mx);
}
