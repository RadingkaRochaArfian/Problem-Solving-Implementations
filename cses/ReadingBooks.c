#include <stdio.h>
typedef long long ll;
void solve(ll n) {
  ll sum = 0;
  ll biggest = -1;
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    sum += x;
    biggest = (biggest < x) ? x : biggest;
  }
  sum = (sum > 2 * biggest) ? sum : 2 * biggest;
  printf("%lld\n", sum);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
