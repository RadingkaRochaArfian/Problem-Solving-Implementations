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
    r[i] = arr[mid + 1 + i];
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
void solve(ll n) {
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  sort(arr, 0, n - 1);
  ll l_sum = 0;
  for (ll i = 0; i < n; i++) {
    if (l_sum + 1 < arr[i]) {
      printf("%lld\n", l_sum + 1);
      return;
    } else {
      l_sum += arr[i];
    }
  }
  printf("%lld\n", l_sum + 1);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}