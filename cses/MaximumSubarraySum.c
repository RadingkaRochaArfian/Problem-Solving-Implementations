#include <stdio.h>
typedef long long ll;
void solve(ll n) {
  ll list[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &list[i]);
  }
  ll max_sub_sum = list[0];
  ll psum_i = list[0];
  ll psum_min = (0 < list[0]) ? 0 : list[0];
  for (ll i = 1; i < n; i++) {
    psum_i += list[i];
    ll max_sub_sum_i = psum_i - psum_min;
    max_sub_sum = (max_sub_sum < max_sub_sum_i) ? max_sub_sum_i : max_sub_sum;
    psum_min = (psum_i < psum_min) ? psum_i : psum_min;
  }
  printf("%lld\n", max_sub_sum);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}