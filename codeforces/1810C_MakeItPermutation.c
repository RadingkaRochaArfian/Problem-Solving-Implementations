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
  ll n, c, d;
  scanf("%lld %lld %lld", &n, &c, &d);
  ll a[n], b[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a, 0, n - 1);
  ll m = 0;
  for (ll i = 0; i < n; i++) {
    if (i == 0 || a[i] != a[i - 1]) {
      b[m++] = a[i];
    }
  }
  ll dup_cost = (n - m) * c;
  ll ans = 1e18;
  for (ll i = 1; i <= m; i++) {
    ll k = b[i - 1];
    ans =
        (((m - i) * c + (k - i) * d) < ans) ? ((m - i) * c + (k - i) * d) : ans;
  }
  ll cost_1 = m * c + d;
  ans = (cost_1 < ans) ? cost_1 : ans;
  printf("%lld\n", ans + dup_cost);
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}