#include <stdio.h>
int main() {
  char s[] = {"897"};
  int len = sizeof(s) / sizeof(s[0]) - 1; // delete null terminator
  int sum = 0;
  for (int i = 0; i < len; i++) {
    int num = s[i] - '0';
    sum += num;
  }
  printf("Sum of {897}: %d\n", sum);
}
