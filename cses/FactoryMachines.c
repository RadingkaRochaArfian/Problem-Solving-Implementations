#include <stdio.h>
typedef long long ll;
ll findWorstSecond(ll arr[], ll n) {
  ll ans = arr[0];
  for (ll i = 1; i < n; i++) {
    if (ans < arr[i])
      ans = arr[i];
  }
  return ans;
}
int capableToMake(ll arr[], ll n, ll t, ll timeLimit) {
  ll totalProd = 0;
  for (int i = 0; i < n; i++) {
    totalProd += timeLimit / arr[i];
    if (totalProd >= t)
      return 1;
  }
  return 0;
}
ll findSecondLimitLowerBound(ll arr[], ll n, ll t, ll maxSecond) {
  ll left = 1, right = maxSecond;
  ll ans = maxSecond;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (capableToMake(arr, n, t, mid)) {
      right = mid - 1;
      ans = mid;
    } else {
      left = mid + 1;
    }
  }
  return ans;
}
void solve(ll n, ll t) {
  ll arrSecond[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arrSecond[i]);
  }
  ll maxSecond = findWorstSecond(arrSecond, n) * t;
  ll ans = findSecondLimitLowerBound(arrSecond, n, t, maxSecond);
  printf("%lld\n", ans);
}
int main() {
  ll n, t;
  scanf("%lld %lld", &n, &t);
  solve(n, t);
}
