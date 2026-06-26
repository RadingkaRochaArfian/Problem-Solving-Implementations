#include <stdio.h>
#include <string.h>
typedef long long ll;
#define MAXN 200005

void updateBit(int bit[], ll n, int idx, int val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int findElementOnStep(int bit[], int n, int pos1) {
  int pos0Step = 0;
  int bitmask = 1;
  while (bitmask << 1 <= n) {
    bitmask <<= 1;
  }
  while (bitmask != 0) {
    int next = pos0Step + bitmask;
    if (next <= n && bit[next] < pos1) {
      pos0Step = next;
      pos1 -= bit[next];
    }
    bitmask >>= 1;
  }
  return pos0Step + 1;
}
void solve(ll n, ll k) {
  int bit[MAXN];
  memset(bit, 0, sizeof(bit));
  for (int i = 1; i <= n; i++) {
    updateBit(bit, n, i, 1);
  }
  int pos = 0;
  ll arrLen = n;
  for (int i = 0; i < n; i++) {
    pos = (pos + k) % arrLen;
    int elemen = findElementOnStep(bit, n, pos + 1);
    printf("%d ", elemen);
    updateBit(bit, n, elemen, -1);
    arrLen--;
  }
}
int main() {
  ll n, k;
  scanf("%lld %lld", &n, &k);
  solve(n, k);
}
