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
void solve(ll n, ll m) {
  ll arr[n];
  ll total_block = 0;
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    total_block += arr[i];
  }
  sort(arr, 0, n - 1);
  ll y = 0;
  for (ll i = 0; i < n; i++) {
    if (arr[i] > y) {
      y++;
    }
  }
  ll min_keep = n + (arr[n - 1] - y);
  printf("%lld\n", (total_block - min_keep));
}
int main() {
  ll n, m;
  scanf("%lld %lld", &n, &m);
  solve(n, m);
}
