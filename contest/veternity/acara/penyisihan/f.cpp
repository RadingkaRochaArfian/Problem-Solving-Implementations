#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll truk[m];
  for (ll i = 0; i < m; i++) {
    truk[i] = 0;
  }
  ll idxTruk = 0;
  for (int i = 0; i < n; i++) {
    ll j = 0;
    while (j < k && i < n) {
      truk[idxTruk] += arr[i++];
      j++;
    }
    idxTruk++;
  }
  ll mx = truk[0];
  for (ll i = 1; i < m; i++) {
    mx = max(mx, truk[i]);
  }
  cout << mx << endl;
}
int main() { solve(); }
