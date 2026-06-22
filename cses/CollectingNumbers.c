#include <stdio.h>
typedef long long ll;
void solve(ll n) {
  ll arr[200005];
  for (ll i = 1; i <= n; i++) {
    ll x;
    scanf("%lld", &x);
    arr[x] = i;
  }
  ll round = 1;
  for (ll i = 2; i <= n; i++) {
    if (arr[i] < arr[i - 1]) {
      round++;
    }
  }
  printf("%lld\n", round);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}