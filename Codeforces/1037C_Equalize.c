#include <stdio.h>
typedef long long ll;
void solve(ll n) {
  char a[n + 1], b[n + 1];
  scanf("%s %s", a, b);
  ll cost = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      if (i + 1 < n) {
        if (a[i + 1] == b[i] && a[i] == b[i + 1]) {
          i++;
          cost++;
        } else
          cost++;
      } else
        cost++;
    }
  }
  printf("%lld\n", cost);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
//reference: https://github.com/soumik9876/Codeforces-solutions/blob/master/codeforces%201037%20C.%20Equalize.cpp
