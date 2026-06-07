#include <stdio.h>
typedef long long ll;
void solve(ll n, ll m, ll x, ll y, ll k) {
  ll total_step = 0;
  for (ll i = 0; i < k; i++) {
    ll dx, dy;
    scanf("%lld %lld", &dx, &dy);
    ll step_x, step_y;
    if (dx > 0) {
      step_x = (n - x) / dx;
    } else if (dx < 0) {
      step_x = (x - 1) / (-dx);
    } else {
      step_x = 2000000009;
    }
    if (dy > 0) {
      step_y = (m - y) / dy;
    } else if (dy < 0) {
      step_y = (y - 1) / (-dy);
    } else {
      step_y = 2000000009;
    }
    ll curr_step = (step_x < step_y) ? step_x : step_y;
    total_step += curr_step;
    y += curr_step * dy;
    x += curr_step * dx;
  }
  printf("%lld\n", total_step);
}
int main() {
  ll n, m, x, y, k;
  scanf("%lld %lld %lld %lld %lld", &n, &m, &x, &y, &k);
  solve(n, m, x, y, k);
}