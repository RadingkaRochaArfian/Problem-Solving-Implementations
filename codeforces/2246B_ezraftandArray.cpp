#include <iostream>
#define ll long long
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1 << endl;
    return;
  }
  ll arr[n];
  arr[0] = 1;
  arr[1] = 2;
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (idx < 2) {
      cout << arr[idx++] << " ";
      continue;
    }
    ll sum = 0;
    for (int j = 0; j < idx; j++) {
      sum += arr[j];
    }
    cout << sum << " ";
    arr[idx++] = sum;
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
