#include <stdio.h>
#include <string.h>
typedef long long ll;
void josephus_2(ll arr[], ll n, ll k) {
  if (n == 1) {
    printf("%lld", arr[0]);
    return;
  }
  if (n == 2) {
    printf("%lld ", arr[0]);
    josephus_2(arr, 1, k);
    return;
  }
  ll taken = 0;
  ll arr_taken[n];
  memset(arr_taken, 0, sizeof(arr_taken));
  for (ll i = k; i < n; i += k + 1) {
    printf("%lld ", arr[i]);
    taken++;
    arr_taken[i] = 1;
  }
  ll new_arr[n - taken];
  ll new_arr_idx = 0;
  for (ll i = 0; i < n; i++) {
    if (!arr_taken[i]) {
      new_arr[new_arr_idx++] = i + 1;
    }
  }
  josephus_2(new_arr, new_arr_idx, k);
}
int main() {
  ll n, k;
  ll arr[n];
  for (ll i = 1; i <= n; i++) {
    arr[i - 1] = i;
  }
  josephus_2(arr, n, k);
}
