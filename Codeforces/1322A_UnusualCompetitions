#include <stdio.h>
typedef long long ll;
void solve(ll n) {
  char arr[n];
  scanf("%s", arr);
  ll open = 0, close = 0;
  for (ll i = 0; i < n; i++) {
    if (arr[i] == '(') {
      open++;
    } else {
      close++;
    }
  }
  if (close != open) {
    printf("-1\n");
    return;
  }
  ll balance = 0, badIdx = 0, total_cost = 0, bad_cond = 0;
  for (ll i = 0; i < n; i++) {
    if (arr[i] == '(') {
      balance++;
    } else {
      balance--;
    }
    if (!bad_cond && balance < 0) {
      bad_cond = 1;
      badIdx = i;
    }
    if (bad_cond && balance == 0) {
      bad_cond = 0;
      total_cost += (i - badIdx + 1);
    }
  }
  printf("%lld\n", total_cost);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}