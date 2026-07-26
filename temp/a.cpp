#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
void solve() {
  ll n;
  scanf("%lld", &n);
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n % 2 == 1) {
    printf("NO\n");
    return;
  }
  ll odd = LLONG_MIN;
  ll even = LLONG_MAX;
  bool cant = false;
  for (ll i = 0; i < n; i++) {
    if (i % 2 == 0) {
      even = min(even, arr[i]);
    } else {
      odd = max(odd, arr[i]);
      if (arr[i] > arr[i - 1] || abs(arr[i] - arr[i - 1]) == 1) {
        cant = true;
      }
    }
  }
  if (abs(even - odd) < 2 || cant || even < odd) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
