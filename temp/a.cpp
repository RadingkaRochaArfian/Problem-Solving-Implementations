#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void solve() {
  int n;
  cin >> n;
  char last = '*';
  string s;
  cin >> s;
  int streak = 0;
  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    if (last == '*' && s[i] == '#') {
      streak = 1;
      last = '#';
    } else if (s[i] == '#') {
      streak++;
    } else {
      last = '*';
      int count = (streak + 1) / 2;
      maxLen = max(maxLen, count);
    }
  }
  int count = (streak + 1) / 2;
  maxLen = max(maxLen, count);
  cout << maxLen << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
