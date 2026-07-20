#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
typedef struct {
  ll val;
  ll idx1;
} Num;
typedef struct {
  ll sum;
  ll i;
  ll j;
} TwoSum;
void merge(Num arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  Num l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].val < r[j].val) {
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
void sort(Num arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
void merge2(TwoSum arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  TwoSum l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].sum < r[j].sum) {
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
void sort2(TwoSum arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sort2(arr, left, mid);
    sort2(arr, mid + 1, right);
    merge2(arr, left, mid, right);
  }
}
ll binarySearch(TwoSum arr[], ll left, ll right, ll target) {
  while (left < right) {
    ll mid = left + (right - left) / 2;
    if (arr[mid].sum == target)
      return mid;
    if (arr[mid].sum < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}
int isDiff(ll i1, ll j1, ll i2, ll j2) {
  if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
    return 1;
  }
  return 0;
}
void solve(ll n, ll x) {
  Num arr[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i].val);
    arr[i].idx1 = i + 1;
  }
  sort(arr, 0, n - 1);
  ll len = n * (n - 1) / 2;
  TwoSum arr2[len];
  ll arr2Idx = 0;
  for (ll i = 0; i < n - 1; i++) {
    for (ll j = i + 1; j < n; j++) {
      arr2[arr2Idx].sum = arr[i].val + arr[j].val;
      arr2[arr2Idx].i = i;
      arr2[arr2Idx].j = j;
      arr2Idx++;
    }
  }
  sort2(arr2, 0, len - 1);
  for (ll i = 0; i < len; i++) {
    ll left = x - arr2[i].sum;
    ll pos = binarySearch(arr2, 0, len - 1, left);
    if (pos != -1) {
      ll i1 = arr2[i].i, j1 = arr2[i].j;
      ll i2 = arr2[pos].i, j2 = arr2[pos].j;
      if (isDiff(i1, j1, i2, j2)) {
        printf("%lld %lld %lld %lld", arr[i1].idx1, arr[i2].idx1, arr[j1].idx1,
               arr[j2].idx1);
        return;
      }
      ll temp = pos - 1;
      while (temp >= 0 && arr2[temp].sum == left) {
        i2 = arr2[temp].i, j2 = arr2[temp].j;
        if (isDiff(i1, j1, i2, j2)) {
          printf("%lld %lld %lld %lld", arr[i1].idx1, arr[i2].idx1,
                 arr[j1].idx1, arr[j2].idx1);
          return;
        }
        temp--;
      }
      temp = pos + 1;
      while (temp < len && arr2[temp].sum == left) {
        i2 = arr2[temp].i, j2 = arr2[temp].j;
        if (isDiff(i1, j1, i2, j2)) {
          printf("%lld %lld %lld %lld", arr[i1].idx1, arr[i2].idx1,
                 arr[j1].idx1, arr[j2].idx1);
          return;
        }
        temp++;
      }
    }
  }
  printf("IMPOSSIBLE\n");
}
int main() {
  ll n, x;
  scanf("%lld %lld", &n, &x);
  solve(n, x);
}
