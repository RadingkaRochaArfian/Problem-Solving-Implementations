#include <cmath>
#include <cstdlib>
#include <iostream>
typedef long long ll;
using namespace std;
void solve() {
  int n;
  cin >> n;
  ll supply = 0;
  bool can = true;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ll val = x - i;
    supply += val;
    if (supply < 0) {
      can = false;
    }
  }
  if (can)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
