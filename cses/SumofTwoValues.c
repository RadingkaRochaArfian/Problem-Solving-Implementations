#include <stdio.h>
typedef long long ll;
const ll MAX = 400000;
typedef struct {
  ll val;
  ll key;
} Map;
ll get_or_put(Map arr[], ll key, ll val) {
  ll h = key % MAX;
  while (arr[h].val != 0 && arr[h].key != key) {
    h = (h + 1) % MAX;
  }
  if (arr[h].key == key) {
    return arr[h].val;
  }
  if (val != 0) {
    arr[h].val = val;
    arr[h].key = key;
  }
  return 0;
}
void solve(ll n, ll x) {
  Map list[MAX];
  for (ll i = 1; i <= n; i++) {
    ll a;
    scanf("%lld", &a);
    ll invert = x - a;
    ll check = get_or_put(list, invert, 0);
    if (check != 0) {
      printf("%lld %lld\n", check, i);
      return;
    }
    get_or_put(list, a, i);
  }
  printf("IMPOSSIBLE\n");
}
int main() {
  ll n, x;
  scanf("%lld %lld", &n, &x);
  solve(n, x);
}