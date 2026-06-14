#include <stdio.h>
#include <string.h>
#define MAX 200005
typedef long long ll;
typedef struct {
  ll type;
  ll i;
  ll j;
} operation;
typedef struct {
  ll idx;
  ll freq;
  ll val;
} struct_max;
ll get_abs(ll a, ll b) {
  if (a > b)
    return a - b;
  else if (b > a)
    return b - a;
  else
    return a - b;
}
void solve(ll n) {
  ll arr[n];
  ll arr_idx = 0;
  ll arr_freq[MAX];
  memset(arr_freq, 0, sizeof(arr_freq));
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    arr[arr_idx++] = x;
    arr_freq[x]++;
  }
  struct_max max;
  max.idx = -1;
  max.freq = -1;
  max.val = -1;
  for (ll i = 0; i < n; i++) {
    ll x = arr[i];
    if (arr_freq[x] > max.freq) {
      max.idx = i;
      max.freq = arr_freq[x];
      max.val = x;
    }
  }
  ll new_arr[n];
  memcpy(new_arr, arr, sizeof(new_arr));
  ll pos = max.idx;
  operation arr_op[n];
  ll arr_op_idx = 0;
  for (ll i = pos - 1; i >= 0; i--) {
    if (new_arr[i] != max.val) {
      if (new_arr[i] < max.val) {
        arr_op[arr_op_idx].type = 1;
        new_arr[i] = new_arr[i] + get_abs(new_arr[i], new_arr[i + 1]);
      } else {
        arr_op[arr_op_idx].type = 2;
        new_arr[i] = new_arr[i] - get_abs(new_arr[i], new_arr[i + 1]);
      }
      arr_op[arr_op_idx].i = i + 1;
      arr_op[arr_op_idx].j = i + 2;
      arr_op_idx++;
    }
  }
  for (ll i = pos + 1; i < n; i++) {
    if (new_arr[i] != max.val) {
      if (new_arr[i] < max.val) {
        arr_op[arr_op_idx].type = 1;
        new_arr[i] = new_arr[i] + get_abs(new_arr[i], new_arr[i - 1]);
      } else {
        arr_op[arr_op_idx].type = 2;
        new_arr[i] = new_arr[i] - get_abs(new_arr[i], new_arr[i - 1]);
      }
      arr_op[arr_op_idx].i = i + 1;
      arr_op[arr_op_idx].j = i;
      arr_op_idx++;
    }
  }
  printf("%lld\n", arr_op_idx);
  for (ll i = 0; i < arr_op_idx; i++) {
    printf("%lld %lld %lld\n", arr_op[i].type, arr_op[i].i, arr_op[i].j);
  }
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
