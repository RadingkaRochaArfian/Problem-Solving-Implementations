#include <stdio.h>
int horse1[] = {1, 1, -1, -1, 2, -2, 2, -2};
int horse2[] = {2, -2, 2, -2, 1, 1, -1, -1};
int isSafe(int n, int i, int j) {
  return (i >= 0 && j >= 0 && i <= n - 1 && j <= n - 1) ? 1 : 0;
}
void setGrid(int *grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[n * i + j] = -1;
    }
  }
}
void giveGrid(int *grid, int n) {
  int q1[n * n];
  int q2[n * n];
  int rear = 0;
  int front = 0;
  grid[n * 0 + 0] = 0;
  q1[0] = 0;
  q2[0] = 0;
  rear++;
  while (front < rear) {
    int o = q1[front];
    int p = q2[front];
    front++;
    int point = grid[n * o + p];
    for (int i = 0; i < 8; i++) {
      int t1 = o + horse1[i];
      int t2 = p + horse2[i];
      if (isSafe(n, t1, t2) && grid[n * t1 + t2] == -1) {
        q1[rear] = t1;
        q2[rear] = t2;
        rear++;
        grid[n * t1 + t2] = point + 1;
      }
    }
  }
}
void printGrid(int *grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", grid[n * i + j]);
      if (j < n - 1)
        printf(" ");
    }
    printf("\n");
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int grid[n][n];
  setGrid((int *)grid, n);
  giveGrid((int *)grid, n);
  printGrid((int *)grid, n);
}