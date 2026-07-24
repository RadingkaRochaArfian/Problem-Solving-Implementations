#include <stdio.h>
typedef long long ll;
typedef struct {
  int idx1;
  ll val;
} Num;
void solve(int n) {
  Num stack[n];
  int top = 0;
  for (int i = 1; i <= n; i++) {
    ll x;
    scanf("%lld", &x);
    while (top != 0 && stack[top - 1].val >= x)
      top--;
    if (top == 0)
      printf("0 ");
    else
      printf("%d ", stack[top - 1].idx1);
    stack[top].idx1 = i;
    stack[top++].val = x;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  solve(n);
}
