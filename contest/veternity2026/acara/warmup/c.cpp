#include <iostream>
typedef long long ll;
using namespace std;
void solve() {
  ll n;
  cin >> n;
  ll l = 0, r = n - 1;
  while (l < r) {
    ll mid = l + (r - l) / 2;
    cout << "READ " << mid << endl;
    string s;
    cin >> s;
    if (s == "true") {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << "OUTPUT " << l - 1 << endl;
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
