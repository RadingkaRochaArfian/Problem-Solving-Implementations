#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
void solve() {
  ll n, c;
  cin >> n >> c;
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    arr[i] = x;
  }
  sort(arr, arr + n);
  if (c == 0) {
    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (res > 0 && arr[i] < 0) {
        continue;
      }
      res += arr[i];
    }
    cout << res << endl;
    return;
  }
  ll limit = (n + 1) / 2;
  ll need = c * limit;
  ll border = n - limit;
  ll sum = 0;
  for (ll i = n - 1; i >= border; i--) {
    sum += arr[i];
  }
  sum -= need;
  cout << sum << endl;
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
