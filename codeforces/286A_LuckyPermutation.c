#include <stdio.h>
typedef long long ll;
void solve(ll n) {
  if (n % 4 == 3 || n % 4 == 2) {
    printf("-1\n");
    return;
  }
  ll arr[n + 1];
  ll idx = 0;
  for (ll i = 1; i <= n / 2; i += 2) {
    arr[i] = i + 1;
    arr[i + 1] = n - i + 1;
    arr[n - i + 1] = n - i;
    arr[n - i] = i;
  }
  if (n % 2 == 1) {
    arr[(n + 1) / 2] = (n + 1) / 2;
  }
  for (ll i = 1; i <= n; i++) {
    printf("%lld ", arr[i]);
  }
  printf("\n");
}
int main() {
  ll x;
  scanf("%lld", &x);
  solve(x);
}
//assisted by deepseek
