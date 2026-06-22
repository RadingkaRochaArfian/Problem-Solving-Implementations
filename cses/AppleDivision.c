#include <stdio.h>
#define ll long long
 
void merge(ll unsorted[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  ll l1[n1], l2[n2];
  for (ll i = 0; i < n1; i++) {
    l1[i] = unsorted[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    l2[i] = unsorted[mid + 1 + i];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l1[i] < l2[j])
      unsorted[k++] = l1[i++];
    else
      unsorted[k++] = l2[j++];
  }
  while (i < n1)
    unsorted[k++] = l1[i++];
  while (j < n2)
    unsorted[k++] = l2[j++];
}
void operate_merge(ll unsorted[], ll left, ll right) {
  if (left >= right)
    return;
  ll mid = left + (right - left) / 2;
  operate_merge(unsorted, left, mid);
  operate_merge(unsorted, mid + 1, right);
  merge(unsorted, left, mid, right);
}
ll ans = 1e18;
void compare(ll n, ll kotak[], ll sum_g1, ll sum_g2, int i) {
  if (n == i) {
    ll abs = (sum_g1 < sum_g2) ? sum_g2 - sum_g1 : sum_g1 - sum_g2;
    ans = (abs < ans) ? abs : ans;
    return;
  }
  compare(n, kotak, sum_g1 + kotak[i], sum_g2, i + 1);
  compare(n, kotak, sum_g1, sum_g2 + kotak[i], i + 1);
}
int main() {
  ll n;
  scanf("%lld", &n);
  ll kotak[n];
  for (int i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    kotak[i] = x;
  }
  ll g1[n];
  ll g2[n];
  operate_merge(kotak, 0, n - 1);
  compare(sizeof(kotak) / sizeof(kotak[0]), kotak, 0, 0, 0);
  printf("%lld\n", ans);
}