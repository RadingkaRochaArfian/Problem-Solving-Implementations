#include <stdio.h>
typedef long long ll;
void solve() {
  ll n, x, y;
  scanf("%lld %lld %lld", &n, &x, &y);
  ll sum_odd = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    if (x % 2 == 1)
      sum_odd += x;
  }
  ll alice = (x % 2) ^ (sum_odd % 2);
  ll bob = ((x + 3) % 2) ^ (sum_odd % 2);
  ll ans = y % 2;
  if (alice == ans) {
    printf("Alice\n");
  } else {
    printf("Bob\n");
  }
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}