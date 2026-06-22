#include <stdio.h>
#include <string.h>
typedef long long ll;
const int MAX = 200005;
void search(ll arr[], ll *idx, int x) {
  ll l = 0, r = *idx;
  while (l < r) {
    ll mid = l + (r - l) / 2;
    if (arr[mid] > x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (!arr[l])
    (*idx)++;
  arr[l] = x;
}
void solve(ll n) {
  ll arr[MAX];
  memset(arr, 0, MAX * sizeof(ll));
  ll idx = 0;
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    if (!idx) {
      arr[idx++] = x;
    } else {
      search(arr, &idx, x);
    }
  }
  printf("%lld\n", idx);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}