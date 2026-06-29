#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
typedef struct {
  ll start;
  ll end;
  ll idx;
} Range;
void merge(Range arr[], Range temp[], ll left, ll mid, ll right) {
  ll i = left, j = mid + 1, k = left;
  while (i <= mid && j <= right) {
    if (arr[i].start < arr[j].start ||
        (arr[i].start == arr[j].start && arr[i].end > arr[j].end)) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }
  for (ll i = left; i <= right; i++) {
    arr[i] = temp[i];
  }
}
void sort(Range arr[], Range temp[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sort(arr, temp, left, mid);
    sort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
  }
}
void solve(ll n) {
  Range *arr_range = malloc(n * sizeof(Range));
  for (ll i = 0; i < n; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    arr_range[i].start = a;
    arr_range[i].end = b;
    arr_range[i].idx = i;
  }
  Range *temp = malloc(n * sizeof(Range));
  sort(arr_range, temp, 0, n - 1);
  int *arr_a = calloc(n, sizeof(int));
  int *arr_b = calloc(n, sizeof(int));
  ll curr_max = LLONG_MIN;
  for (ll i = 0; i < n; i++) {
    Range curr = arr_range[i];
    if (curr_max != LLONG_MIN && curr.end <= curr_max) {
      arr_b[curr.idx] = 1;
    }
    curr_max = (curr_max < curr.end) ? curr.end : curr_max;
  }
  ll curr_min = LLONG_MAX;
  for (ll i = n - 1; i >= 0; i--) {
    Range curr = arr_range[i];
    if (curr_min != LLONG_MAX && curr_min <= curr.end) {
      arr_a[curr.idx] = 1;
    }
    curr_min = (curr_min > curr.end) ? curr.end : curr_min;
  }
  for (ll i = 0; i < n; i++) {
    printf("%d", arr_a[i]);
    if (i < n - 1) {
      printf(" ");
    }
  }
  printf("\n");
  for (ll i = 0; i < n; i++) {
    printf("%d", arr_b[i]);
    if (i < n - 1) {
      printf(" ");
    }
  }
  printf("\n");
  free(arr_range);
  free(arr_a);
  free(arr_b);
  free(temp);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
