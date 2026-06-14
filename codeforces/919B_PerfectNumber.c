#include <stdio.h>
typedef long long ll;
ll find_sum(ll digit) {
  ll sum = 0;
  while (digit > 0) {
    sum += digit % 10;
    digit /= 10;
  }
  return sum;
}
void solve(ll k) {
  ll count = 0;
  ll digit = 19;
  while (count < k) {
    if (find_sum(digit) == 10) {
      count++;
      if (count == k) {
        printf("%lld\n", digit);
        break;
      }
    }
    digit++;
  }
}
int main() {
  ll k;
  scanf("%lld", &k);
  solve(k);
}
