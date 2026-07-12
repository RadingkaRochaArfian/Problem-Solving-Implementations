#include <iostream>
using ll = long long;
using namespace std;
void solve() {
  ll k;
  cin >> k;
  ll count3 = 0;
  ll count2 = 0;
  ll countMore = 0;
  for (ll i = 0; i < k; i++) {
    ll x;
    cin >> x;
    if (x % 3 == 0) {
      count3++;
    } else if (x == 2) {
      count2++;
    } else if (x > 3) {
      countMore++;
    }
  }
  if (count3 > 0 || count2 > 1 || countMore > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
