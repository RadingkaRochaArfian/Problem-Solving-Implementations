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
ll find_index(ll next[], ll idx) {
  if (idx < 0)
    return -1;
  if (next[idx] == idx)
    return idx;
  return next[idx] = find_index(next, next[idx]);
}
void solve(ll n, ll m) {
  ll arr_n[n], arr_m[m];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr_n[i]);
  }
  for (ll i = 0; i < m; i++) {
    scanf("%lld", &arr_m[i]);
  }
  sort(arr_n, 0, n - 1);
  ll next[n];
  for (ll i = 0; i < n; i++)
    next[i] = i;
  for (ll i = 0; i < m; i++) {
    ll left = 0, right = n - 1, flag = -1;
    while (left <= right) {
      ll mid = left + (right - left) / 2;
      if (arr_n[mid] <= arr_m[i]) {
        flag = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (flag == -1) {
      printf("-1\n");
      continue;
    }
    ll index = find_index(next, flag);
    if (index >= 0) {
      printf("%lld\n", arr_n[index]);
      if (index > 0)
        next[index] = find_index(next, index - 1);
      else
        next[index] = -1;
    } else {
      printf("-1\n");
    }
  }
}
int main() {
  ll n, m;
  scanf("%lld %lld", &n, &m);
  solve(n, m);
}