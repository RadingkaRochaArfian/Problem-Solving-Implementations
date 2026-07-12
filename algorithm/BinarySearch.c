#include <stdio.h>
int binarySearchRecursive(int arr[], int left, int right, int elemenTarget) {
  if (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == elemenTarget) {
      return mid;
    }
    if (arr[mid] > elemenTarget) {
      binarySearchRecursive(arr, left, mid - 1, elemenTarget);
    }
    return binarySearchRecursive(arr, mid + 1, right, elemenTarget);
  }
  return -1;
}
int binarySearchLoop(int arr[], int size, int elemenTarget) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == elemenTarget) {
      return mid;
    }
    if (arr[mid] < elemenTarget) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
int main() {
  int arr[] = {1, 3, 5, 7, 9};
  printf("Recursive: %d\nLoop: %d\n",
         binarySearchRecursive(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, 7),
         binarySearchLoop(arr, (sizeof(arr) / sizeof(arr[0])), 7));
}
/*
when to use:
-minimize to maximum problem
*/
