#include <stdio.h>
void sort(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int l[n1], r[n2];
  for (int i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i] < r[j]) {
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
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    sort(arr, left, mid, right);
  }
}
int main() {
  int arr[] = {5, 3, 5, 8, 3, 9, 10, 7, 11};
  mergeSort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
  for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
    printf("%d", arr[i]);
    if (i < (sizeof(arr) / sizeof(arr[0])) - 1)
      printf(" ");
  }
  printf("\n");
}
