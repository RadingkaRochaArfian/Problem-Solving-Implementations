#include <stdio.h>
#define ll long long
void sort(ll arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  ll l[n1], r[n2];
  for (int i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++) {
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
void mergeSort(ll arr[], int left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    sort(arr, left, mid, right);
  }
}
void solve(ll wList[], ll n, ll aList[], ll m, ll k) {
  ll i = 0, j = 0;
  ll ans = 0;
  while (i < n && j < m) {
    if (wList[i] < aList[j] - k) {
      i++;
    } else if (wList[i] > aList[j] + k) {
      j++;
    } else {
      ans++;
      i++;
      j++;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  ll n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  ll wantList[n];
  ll avList[m];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &wantList[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%lld", &avList[i]);
  }
  mergeSort(wantList, 0, n - 1);
  mergeSort(avList, 0, m - 1);
  solve(wantList, n, avList, m, k);
}