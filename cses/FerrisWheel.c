#include <stdio.h>
#define ll long long
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
    if (l[i] < r[j])
      arr[k++] = l[i++];
    else
      arr[k++] = r[j++];
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
void solve(ll n, ll x) {
  ll ank[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &ank[i]);
  }
  sort(ank, 0, n - 1);
  ll i = 0, j = n - 1, sum = 0;
  while (i <= j) {
    if (i == j) {
      sum++;
      break;
    }
    ll left = ank[i];
    ll right = ank[j];
    if (right + left <= x) {
      i++;
      j--;
    } else {
      j--;
    }
    sum++;
  }
  printf("%lld\n", sum);
}
int main() {
  ll n, x;
  scanf("%lld %lld", &n, &x);
  solve(n, x);
}