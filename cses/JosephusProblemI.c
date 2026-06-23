#include <stdio.h>
void josephus_1(int arr[], int n) {
  if (n == 1) {
    printf("%d\n", arr[0]);
    return;
  }
  for (int i = 1; i < n; i += 2) {
    printf("%d ", arr[i]);
  }
  int new_arr[(n + 1) / 2];
  int new_arr_idx = 0;
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      new_arr[new_arr_idx++] = arr[i];
    }
  } else {
    new_arr[new_arr_idx++] = arr[n - 1];
    for (int i = 0; i < n - 1; i += 2) {
      new_arr[new_arr_idx++] = arr[i];
    }
  }
  josephus_1(new_arr, (n + 1) / 2);
}
void solve(int n) {
  int arr_num[n];
  for (int i = 0; i < n; i++) {
    arr_num[i] = i + 1;
  }
  josephus_1(arr_num, n);
}
int main() {
  int n;
  scanf("%d", &n);
  solve(n);
}
