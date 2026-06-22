#include <stdio.h>
typedef long long ll;
void swap(ll *a, ll *b) {
  ll temp = *a;
  *a = *b;
  *b = temp;
}
void solve(ll n) {
  ll m;
  scanf("%lld", &m);
  ll arr[n + 1];
  ll pos[n + 1];
  for (ll i = 1; i <= n; i++) {
    ll x;
    scanf("%lld", &x);
    arr[x] = i;
    pos[i] = x;
  }
  ll rounds = 1;
  for (ll i = 2; i <= n; i++) {
    if (arr[i] < arr[i - 1]) {
      rounds++;
    }
  }
  while (m--) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    if (a > b)
      swap(&a, &b);
    ll x = pos[a];
    ll y = pos[b];
    if (arr[x + 1] > a && arr[x + 1] < b)
      rounds++;
    if (arr[x - 1] > a && arr[x - 1] < b)
      rounds--;
    if (arr[y + 1] > a && arr[y + 1] < b)
      rounds--;
    if (arr[y - 1] > a && arr[y - 1] < b)
      rounds++;
    if (x == (y + 1))
      rounds--;
    if (x == (y - 1))
      rounds++;
    printf("%lld\n", rounds);
    arr[x] = b;
    arr[y] = a;
    pos[a] = y;
    pos[b] = x;
  }
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}