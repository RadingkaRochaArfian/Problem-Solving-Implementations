#include <stdio.h>
typedef long long ll;
typedef struct {
  ll val;
  ll idx1;
} Num;
void sort(Num arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  Num l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].val < r[j].val) {
      arr[k++] = l[i++];
    } else {
      arr[k++] = r[j++];
    }
  }
  while (i < n1) {
    arr[k++] = l[i++];
  }
  while (j < n2) {
    arr[k++] = r[j++];
  }
}
void mergeSort(Num arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    sort(arr, left, mid, right);
  }
}
void solve(ll n, ll x) {
  Num arr[n];
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i - 1].val);
    arr[i - 1].idx1 = i;
  }
  int flag = 0;
  mergeSort(arr, 0, n - 1);
  ll threeVal[3];
  for (ll i = 0; i < n - 2; i++) {
    ll left = x - arr[i].val;
    ll right;
    ll l = i + 1, r = n - 1;
    while (l < r) {
      right = arr[l].val + arr[r].val;
      ll sum = arr[i].val + right;
      if (left == right) {
        flag = 1;
        threeVal[0] = arr[i].idx1;
        threeVal[1] = arr[l].idx1;
        threeVal[2] = arr[r].idx1;
        break;
      } else if (sum > x) {
        r--;
      } else {
        l++;
      }
    }
  }
  if (flag) {
    printf("%lld %lld %lld\n", threeVal[0], threeVal[1], threeVal[2]);
  } else {
    printf("IMPOSSIBLE\n");
  }
}
int main() {
  ll n, x;
  scanf("%lld %lld", &n, &x);
  solve(n, x);
}
