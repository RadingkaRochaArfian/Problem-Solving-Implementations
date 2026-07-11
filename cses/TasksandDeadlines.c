#include <stdio.h>
typedef struct {
  long long dur;
  long long ded;
} Task;

void sort(Task arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  Task l[n1], r[n2];
  for (int i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].dur < r[j].dur) {
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
void mergeSort(Task arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    sort(arr, left, mid, right);
  }
}
void solve(int n) {
  Task arr[n];
  for (int i = 0; i < n; i++) {
    int a, d;
    scanf("%d %d", &a, &d);
    arr[i].dur = a;
    arr[i].ded = d;
  }
  mergeSort(arr, 0, n - 1);
  long long time = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    time += arr[i].dur;
    ans += arr[i].ded - time;
  }
  printf("%lld\n", ans);
}
int main() {
  int n;
  scanf("%d", &n);
  solve(n);
}
