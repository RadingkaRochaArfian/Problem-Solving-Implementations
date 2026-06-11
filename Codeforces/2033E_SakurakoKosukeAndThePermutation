#include <stdio.h>
#include <string.h>
typedef long long ll;
void solve() {
  ll n;
  scanf("%lld", &n);
  ll arr[n + 1];
  for (ll i = 1; i <= n; i++) {
    ll x;
    scanf("%lld", &x);
    arr[i] = x;
  }
  int simple_f = 1;
  for (ll i = 1; i <= n; i++) {
    if (arr[arr[i]] != i) {
      simple_f = 0;
      break;
    }
  }
  if (simple_f) {
    printf("0\n");
    return;
  }
  ll s_sum = 0;
  ll arr_vis[n + 1];
  memset(arr_vis, 0, (n + 1) * sizeof(ll));
  for (ll i = 1; i <= n; i++) {
    if (!arr_vis[i]) {
      ll curr_i = i;
      ll c_length = 0;
      while (!arr_vis[curr_i]) {
        arr_vis[curr_i] = 1;
        curr_i = arr[curr_i];
        c_length++;
      }
      s_sum += (c_length - 1) / 2;
    }
  }
  printf("%lld\n", s_sum);
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}