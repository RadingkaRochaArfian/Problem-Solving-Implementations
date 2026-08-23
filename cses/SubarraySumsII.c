#include <stdio.h>
#define SIZE 400005
typedef long long ll;
int hash(ll x) {
  x %= SIZE;
  if (x < 0) {
    x += SIZE;
  }
  return x;
}
ll *mp(ll key[], ll val[], ll x) {
  int idx = hash(x);
  while (val[idx] != 0 && key[idx] != x) {
    idx++;
    if (idx == SIZE) {
      idx = 0;
    }
  }
  key[idx] = x;
  return &val[idx];
}
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  ll p = 0;
  ll key[SIZE];
  ll val[SIZE];
  (*mp(key, val, 0))++;
  long long total = 0;
  for (int i = 1; i <= n; i++) {
    int m;
    scanf("%d", &m);
    p += m;
    long long y = p - x;
    total += *mp(key, val, y);
    (*mp(key, val, p))++;
  }
  printf("%lld\n", total);
}
