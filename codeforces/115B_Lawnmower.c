#include <stdio.h>
#include <stdlib.h>
#define MAX 150
void solve(int n, int m) {
  char grid[MAX][MAX + 1];
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }
  int pos_i = 0;
  int pos_j = 0;
  int total_step = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'W') {
          total_step += abs(i - pos_i) + abs(j - pos_j);
          pos_i = i;
          pos_j = j;
        }
      }
    } else {
      for (int j = m - 1; j >= 0; j--) {
        if (grid[i][j] == 'W') {
          total_step += abs(i - pos_i) + abs(j - pos_j);
          pos_i = i;
          pos_j = j;
        }
      }
    }
  }
  printf("%d\n", total_step);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  solve(n, m);
}
