#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (k > (n / 2)) {
    cout << -1 << endl;
    return;
  }
  int l = 0, r = n - 1;
  int turn = 0;
  int count = 0;
  while (l < r && turn != k) {
    if (s[l++] != 'R') {
      count++;
    }
    if (s[r--] != 'L') {
      count++;
    }
    turn++;
  }
  cout << count << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
