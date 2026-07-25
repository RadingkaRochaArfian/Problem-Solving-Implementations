#include <stdio.h>
typedef long long ll;
void solve(ll n, ll x) {
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  ll j = 0, i = 0;
  ll sum = 0;
  ll cnt = 0;
  while (j < n) {
    sum += arr[j];
    while (sum > x) {
      sum -= arr[i];
      i++;
    }
    if (sum == x)
      cnt++;
    j++;
  }
  printf("%lld\n", cnt);
}
int main() {
  ll n, x;
  scanf("%lld %lld", &n, &x);
  solve(n, x);
}
