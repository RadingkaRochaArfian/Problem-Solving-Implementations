#include <stdio.h>
#include <string.h>
typedef long long ll;
ll gcd(ll a, ll b) {
  while (b != 0) {
    ll temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
void solve() {
  ll n;
  scanf("%lld", &n);
  ll arr1[n], arr2[n], arr_visited[n];
  memset(arr_visited, 0, n * sizeof(ll));
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr1[i]);
  }
  ll curr_g = 0;
  ll idx_arr2 = 0;
  while (idx_arr2 < n) {
    ll best_g = 0;
    for (ll i = 0; i < n; i++) {
      if (!arr_visited[i]) {
        ll g = gcd(arr1[i], curr_g);
        if (g > best_g)
          best_g = g;
      }
    }
    for (ll i = 0; i < n; i++) {
      if (!arr_visited[i] && gcd(arr1[i], curr_g) == best_g) {
        arr2[idx_arr2++] = arr1[i];
        arr_visited[i] = 1;
      }
    }
    curr_g = best_g;
  }
  for (ll i = 0; i < n; i++) {
    printf("%lld ", arr2[i]);
  }
  printf("\n");
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}