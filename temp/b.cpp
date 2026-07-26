#include <cstdlib>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
void solve() {
  ll n, k;
  cin >> n >> k;
  ll half = n / 2;
  if (abs(n - k) == 1) {
    cout << -1 << endl;
    return;
  }
  string s = "1";
  ll i = 1;
  string last = "1";
  ll loop = k / 2;
  while (i < n) {
    ll j = 0;
    while (k != 0 && j < loop) {
      s += last;
      i++;
      j++;
      k--;
    }
    if (!(i < n))
      break;
    loop = abs(n - loop);
    if (last == "1") {
      s += "0";
      last = "0";
    } else {
      s += "1";
      last = "1";
    }
    i++;
  }
  cout << s << endl;
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
