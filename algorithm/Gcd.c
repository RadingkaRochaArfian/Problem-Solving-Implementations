
#include <stdio.h>
int gcdRecursive(int a, int b) {
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  if (b == 0)
    return a;
  return gcdRecursive(b, a % b);
}
int gcdLoop(int a, int b) {
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
int main() {
  printf("GCD recursive (10,3): %d\n", gcdRecursive(10, 3));
  printf("GCD loop (3,10): %d\n", gcdLoop(3, 10));
}
