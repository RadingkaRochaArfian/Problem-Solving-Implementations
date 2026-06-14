#include <stdio.h>
typedef long long ll;
void merge(ll arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  ll l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i] < r[j]) {
      arr[k++] = l[i++];
    } else {
      arr[k++] = r[j++];
    }
  }
  while (i < n1) {
    arr[k++] = l[i++];
  }
  while (j < n2) {
    arr[k++] = r[j++];
  }
}
void sort(ll arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
void solve() {
  ll n;
  scanf("%lld", &n);
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  sort(arr, 0, n - 1);
  ll leg_val1 = -1, leg_val1_idx = -1, leg_val2 = -1, leg_val2_idx = -1;
  for (ll i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      leg_val1 = arr[i];
      leg_val1_idx = i - 1;
      break;
    }
  }
  if (leg_val1 == -1) {
    printf("-1\n");
    return;
  }
  for (ll i = leg_val1_idx + 2; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      leg_val2 = arr[i];
      leg_val2_idx = i;
      break;
    }
  }
  if (leg_val2 != -1) {
    printf("%lld %lld %lld %lld\n", leg_val1, leg_val1, leg_val2, leg_val2);
    return;
  }
  ll dif_list[n];
  ll dif_idx = 0;
  ll base1 = -1, base2 = -1;
  for (ll i = 1; i <= n; i++) {
    if (i - 1 == leg_val1_idx || i - 1 == leg_val1_idx + 1) {
      continue;
    }
    dif_list[dif_idx++] = arr[i - 1];
  }
  for (ll i = 0; i < dif_idx - 1; i++) {
    if (dif_list[i + 1] - dif_list[i] < 2 * leg_val1) {
      base1 = dif_list[i];
      base2 = dif_list[i + 1];
      break;
    }
  }
  if (base1 == -1 || dif_idx < 2) {
    printf("-1\n");
    return;
  } else {
    printf("%lld %lld %lld %lld\n", leg_val1, leg_val1, base1, base2);
    return;
  }
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
//reference: https://www.youtube.com/watch?v=_RDcdgqm0Y8
