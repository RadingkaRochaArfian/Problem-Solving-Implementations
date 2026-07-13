#include <stdio.h>
int sumOfDigit(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
int main() { printf("Sum of digit from 89: %d", sumOfDigit(89)); }
