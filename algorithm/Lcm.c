#include <stdio.h>
int lcmWithLoop(int a, int b) {
  int ans = (a > b) ? a : b;
  while (1) {
    if (ans % a == 0 && ans % b == 0) {
      break;
    }
    ans++;
  }
  return ans;
}
int gcd(int a, int b) {
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int lcmWithGcd(int a, int b) { return (a / gcd(a, b)) * b; }
int main() {
  printf("LCM 20,15: %d\n", lcmWithGcd(20, 15));
  printf("LCM 15,20 : %d\n", lcmWithLoop(15, 20));
}
