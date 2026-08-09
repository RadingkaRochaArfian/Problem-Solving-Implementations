#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
void solve() {
  ll arr[3];
  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
  }
  ll mx = *max_element(arr, arr + 3);
  ll mn = *min_element(arr, arr + 3);
  for (int i = 0; i < 3; i++) {
    if (arr[i] == mx) {
      ll temp = arr[(i + 1) % 3] + arr[(i + 2) % 3];
      if ((temp - mn) < (mx - mn)) {
        mx = temp;
      }
    }
  }
  cout << mx - mn << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
