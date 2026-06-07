#include <stdio.h>
#include <string.h>
typedef long long ll;
void solve(ll n) {
  ll a1, a2, a3, a4, a5, a6;
  ll q1, q2, q3, q4;
  printf("? 1 2\n");
  fflush(stdout);
  scanf("%lld", &q1);
  printf("? 2 3\n");
  fflush(stdout);
  scanf("%lld", &q2);
  printf("? 3 4\n");
  fflush(stdout);
  scanf("%lld", &q3);
  printf("? 4 5\n");
  fflush(stdout);
  scanf("%lld", &q4);
  ll arr[] = {4, 8, 15, 16, 23, 42};
  int arr_f[n];
  memset(arr_f, 0, n * sizeof(int));
  for (ll i = 0; i < n; i++) {
    if (q1 % arr[i] == 0 && q2 % arr[i] == 0) {
      ll temp_a2 = arr[i];
      ll temp_a1 = q1 / temp_a2;
      ll temp_a3 = q2 / temp_a2;
      int f_a1 = 0, f_a3 = 0;
      for (ll j = 0; j < n; j++) {
        if (temp_a1 == arr[j])
          f_a1 = 1;
        if (temp_a3 == arr[j])
          f_a3 = 1;
      }
      if (!f_a1 || !f_a3) {
        continue;
      }
      ll temp_a4 = q3 / temp_a3;
      ll temp_a5 = q4 / temp_a4;
      int f_a4 = 0, f_a5 = 0;
      for (ll j = 0; j < n; j++) {
        if (temp_a4 == arr[j])
          f_a4 = 1;
        if (temp_a5 == arr[j])
          f_a5 = 5;
      }
      if (f_a4 && f_a5) {
        a2 = temp_a2;
        arr_f[i] = 1;
        break;
      }
    }
  }
  a1 = q1 / a2;
  a3 = q2 / a2;
  a4 = q3 / a3;
  a5 = q4 / a4;
  for (ll i = 0; i < n; i++) {
    if (!arr_f[i] && (arr[i] == a1 || arr[i] == a2 || arr[i] == a3 ||
                      arr[i] == a4 || arr[i] == a5)) {
      arr_f[i] = 1;
    }
  }
  for (ll i = 0; i < n; i++) {
    if (!arr_f[i]) {
      a6 = arr[i];
      break;
    }
  }
  printf("! %lld %lld %lld %lld %lld %lld\n", a1, a2, a3, a4, a5, a6);
}
int main() { solve(6); }
