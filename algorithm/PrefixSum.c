#include <stdio.h>
#include <stdlib.h>
int *findPrefixSum(int arr[], int n) {
  int *prefixSum = (int *)malloc((n + 1) * sizeof(int));
  prefixSum[0] = 0;
  for (int i = 0; i < n; i++) {
    prefixSum[i + 1] = prefixSum[i] + arr[i];
  }
  return prefixSum;
}
int main() {
  int array[] = {7, 8, 9, 10};
  int len = sizeof(array) / sizeof(array[0]);
  int *prefixSum = findPrefixSum(array, len);
  printf("Sum of array {7,8,9,10} = %d", prefixSum[len]);
}
