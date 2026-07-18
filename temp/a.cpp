#include <cstdlib>
#include <iostream>
typedef long long ll;
using namespace std;
void solve() {
  int n;
  cin >> n;
  ll sum = 0;
  ll iPlus = 0;
  ll iMinus = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      iPlus++;
    } else {
      iMinus++;
    }
    sum += x;
  }
  if (n == 1) {
    cout << "NO" << endl;
    return;
  }
  if (sum == 0) {
    cout << "YES" << endl;
    return;
  }
  if (iPlus != iMinus && abs(iPlus - iMinus) > 2) {
    sum = iPlus + iMinus;
    ll diff = (iPlus + iMinus) / 2;
    if (iPlus > iMinus) {
      ll req = abs(iMinus - diff);
      req /= 2;
      req *= 2;
      iPlus -= req;
      iMinus += req;
    } else {
      ll req = abs(iPlus - diff);
      req /= 2;
      req *= 2;
      iPlus += req;
      iMinus -= req;
    }
  }
  if (iPlus != iMinus) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
