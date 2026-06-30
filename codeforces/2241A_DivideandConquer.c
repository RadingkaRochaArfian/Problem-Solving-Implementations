typedef long long ll;
#include <stdio.h>
void solve() {
  ll a, b;
  scanf("%lld %lld", &a, &b);
  printf("%s\n", ((a % b == 0) ? "YES" : "NO"));
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
