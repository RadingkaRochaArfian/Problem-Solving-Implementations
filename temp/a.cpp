#include <cstring>
#include <iostream>
#include <string>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      s.erase(i, 1);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      s.erase(i, 1);
      break;
    }
  }
  cout << s << endl;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
