#include <stdio.h>
typedef long long ll;
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
void solve() {
  ll k, l1, r1, l2, r2;
  scanf("%lld %lld %lld %lld %lld", &k, &l1, &r1, &l2, &r2);
  ll kn = 1, ans = 0;
  for (ll n = 0; kn <= r2; n++) {
    ll min_y = ceil_div(l2, kn);
    ll max_y = r2 / kn;
    ll l = (l1 < min_y) ? min_y : l1;
    ll r = (r1 < max_y) ? r1 : max_y;
    if (r >= l) {
      ans += (r - l + 1);
    }
    kn *= k;
  }
  printf("%lld\n", ans);
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}