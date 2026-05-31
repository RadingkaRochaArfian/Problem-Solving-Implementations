#include <stdio.h>
typedef long long ll;
void solve() {
  ll n;
  scanf("%lld", &n);
  char s[n];
  ll sum_0 = 0;
  for (ll i = 0; i < n; i++) {
    scanf(" %c", &s[i]);
    if (s[i] == '0') {
      sum_0++;
    }
  }
  ll flag = 1;
  for (ll i = 0; i < sum_0; i++) {
    if (s[i] != '0') {
      flag = 0;
    }
  }
  for (ll i = sum_0; i < n; i++) {
    if (s[i] != '1') {
      flag = 0;
    }
  }
  if (flag) {
    printf("Bob\n");
    return;
  }
  ll dif[200005];
  ll m = 0;
  for (ll i = 0; i < sum_0; i++) {
    if (s[i] != '0') {
      dif[m++] = i + 1;
    }
  }
  for (ll i = sum_0; i < n; i++) {
    if (s[i] != '1') {
      dif[m++] = i + 1;
    }
  }
  printf("Alice\n%lld\n", m);
  for (ll i = 0; i < m; i++) {
    printf("%lld ", dif[i]);
  }
  printf("\n");
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
