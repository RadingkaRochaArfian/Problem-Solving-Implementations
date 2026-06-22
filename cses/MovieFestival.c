#include <stdio.h>
#define ll long long
typedef struct {
  ll st;
  ll et;
} Cst;
void merge(Cst arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  Cst l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].et < r[j].et) {
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
void sort(Cst arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
void solve(ll n) {
  Cst list[n];
  for (ll i = 0; i < n; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    list[i].st = a;
    list[i].et = b;
  }
  sort(list, 0, n - 1);
  ll prev_et = list[0].et;
  ll count = 1;
  for (ll i = 1; i < n; i++) {
    if (list[i].st >= prev_et) {
      prev_et = list[i].et;
      count++;
    }
  }
  printf("%lld\n", count);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}