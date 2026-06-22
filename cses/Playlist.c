#include <stdio.h>
#include <string.h>
typedef long long ll;
const int MAX = 100005;
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
  ll a[n], b[n], c[n];
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    a[i] = x;
    b[i] = x;
  }
  sort(b, 0, n - 1);
  for (ll i = 0; i < n; i++) {
    ll l = 0, r = n - 1;
    while (l <= r) {
      ll mid = (l + r) / 2;
      if (b[mid] == a[i]) {
        c[i] = mid;
        break;
      } else if (b[mid] < a[i]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  ll max_len = 0;
  ll left = 0;
  ll last_pos[n];
  memset(last_pos, -1, n * sizeof(ll));
  for (ll right = 0; right < n; right++) {
    ll val = c[right];
    if (last_pos[val] >= left) {
      left = last_pos[val] + 1;
    }
    last_pos[val] = right;
    ll curr_len = right - left + 1;
    if (curr_len > max_len)
      max_len = curr_len;
  }
  printf("%lld\n", max_len);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}