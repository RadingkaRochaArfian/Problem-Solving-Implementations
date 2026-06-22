#include <bits/stdc++.h>
using namespace std;
 
string solve(unordered_map<char, int> kar, int n) {
  string half = "";
  string mid = "";
  for (const auto &init : kar) {
    char ch = init.first;
    int loop = init.second;
    if (loop % 2 == 1) {
      mid = ch;
    }
    string halve = string(loop / 2, ch);
    half += halve;
  }
  string otherHalf = "";
  for (int i = half.length() - 1; i >= 0; i--) {
    otherHalf += half[i];
  }
  return half + mid + otherHalf;
}
 
int main() {
  string input;
  cin >> input;
  int n = input.length();
  unordered_map<char, int> karakter;
  for (int i = 0; i < n; i++) {
    karakter[input[i]]++;
  }
  int ganjil = 0;
  for (const auto &p : karakter) {
    if (p.second % 2 == 1)
      ganjil++;
  }
  if (ganjil > 1) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }
  string ans = solve(karakter, n);
  cout << ans << endl;
}