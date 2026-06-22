#include <stdio.h>
#define ll long long
int find(int a, int b) {
  if ((2 * b - a) % 3 != 0 || (2 * a - b) % 3 != 0 || (2 * b - a) < 0 ||
      (2 * a - b) < 0) {
    return 0;
  }
  return 1;
}
int main() {
  ll n;
  scanf("%lld", &n);
  for (ll i = 0; i < n; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    int flag = find(a, b);
    if (flag == 1)
      printf("%s\n", "YES");
    else
      printf("%s\n", "NO");
  }
}