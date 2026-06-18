#include <stdio.h>
typedef long long ll;
void solve(ll n, ll a, ll b) {
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    ll m = x * a % b;
    ll ans = m / a;
    printf("%lld ", ans);
  }
}
int main() {
  ll n, a, b;
  scanf("%lld %lld %lld", &n, &a, &b);
  solve(n, a, b);
}
