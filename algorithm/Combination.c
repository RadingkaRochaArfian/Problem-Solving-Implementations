#include <stdio.h>
typedef long long ll;
#define MAX_N 200001
const ll MOD = 1000000007;
ll fact[MAX_N], inv[MAX_N], invFact[MAX_N];
void preCompute() {
  fact[0] = fact[1] = inv[1] = invFact[0] = invFact[1] = 1;
  for (int i = 2; i < MAX_N; i++) {
    fact[i] = i * fact[i - 1] % MOD;
    inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
    invFact[i] = inv[i] * invFact[i - 1] % MOD;
  }
}
ll nCrWithPreComp(int n, int r) {
  ll res = invFact[r] * invFact[n - r] % MOD;
  res = (res * fact[n]) % MOD;
  return res;
}
int main() {
  preCompute();
  printf("nCr(5,3) with pre-computation: %lld\n", nCrWithPreComp(5, 3));
}
