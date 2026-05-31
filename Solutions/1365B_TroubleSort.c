#include <stdio.h>
typedef long long ll;
void solve() {
  ll n;
  scanf("%lld", &n);
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  int flag_0 = 0, flag_1 = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    if (x == 1) {
      flag_1 = 1;
    } else if (x == 0) {
      flag_0 = 1;
    }
  }
  if (!flag_0 || !flag_1) {
    for (ll i = 1; i < n; i++) {
      if (arr[i - 1] > arr[i]) {
        printf("No\n");
        return;
      }
    }
  }
  printf("Yes\n");
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
