#define MAX 200005
typedef long long ll;
void update(ll bit[], int n, int idx, ll val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}

int getSumSubarray(ll bit[], int idx) {
  ll sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= idx & -idx;
  }
  return sum;
}

int findActiveIndexAtOrder(ll bit[], int n, int order) {
  int idx = 0;
  int bitmask = 1;

  while (bitmask << 1 <= n) {
    bitmask <<= 1;
  }

  while (bitmask != 0) {
    int next = idx + bitmask;
    if (next <= n && bit[next] < order) {
      idx = next;
      order -= bit[next];
    }
    bitmask >>= 1;
  }

  return idx + 1;
}

int main() { ll bit[MAX]; }
