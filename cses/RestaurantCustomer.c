#include <stdio.h>
#define ll long long
#define max 100005
#include <stdlib.h>
typedef struct {
  ll timeVisit;
  ll mod;
} Visits;
void merge(Visits arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  Visits l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + 1 + i];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].timeVisit < r[j].timeVisit) {
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
void sort(Visits arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
void solve(ll n) {
  ll t = n;
  Visits *vList = malloc(sizeof(Visits) * 2 * n);
  ll a, b;
  for (ll i = 0; i < n; i++) {
    scanf("%lld %lld", &a, &b);
    vList[i * 2].timeVisit = a;
    vList[i * 2].mod = 1;
    vList[i * 2 + 1].timeVisit = b;
    vList[i * 2 + 1].mod = -1;
  }
  sort(vList, 0, n * 2 - 1);
  ll max_v = 0, curr = 0;
  for (ll i = 0; i < 2 * n; i++) {
    curr += vList[i].mod;
    if (max_v < curr)
      max_v = curr;
  }
  printf("%lld\n", max_v);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}