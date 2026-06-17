#include <stdio.h>
#include <string.h>
#define MAX 500
int get(int arr[MAX][MAX], int row, int col) {
  if (row < 0 || col < 0) {
    return 0;
  }
  return arr[row][col];
}
int solve_query(int hor[MAX][MAX], int ver[MAX][MAX]) {
  int r1, c1, r2, c2;
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
  r1--;
  c1--;
  r2--;
  c2--;
  int ans = 0;
  ans += get(hor, r2, c2 - 1) - get(hor, r1 - 1, c2 - 1) -
         get(hor, r2, c1 - 1) + get(hor, r1 - 1, c1 - 1);
  ans += get(ver, r2 - 1, c2) - get(ver, r1 - 1, c2) -
         get(ver, r2 - 1, c1 - 1) + get(ver, r1 - 1, c1 - 1);
  return ans;
}
void solve(int h, int w) {
  char grid[MAX][MAX + 1];
  int hor[MAX][MAX];
  int ver[MAX][MAX];
  memset(hor, 0, sizeof(hor));
  memset(ver, 0, sizeof(ver));
  for (int i = 0; i < h; i++) {
    scanf("%s", grid[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      hor[i][j] =
          get(hor, i - 1, j) + get(hor, i, j - 1) - get(hor, i - 1, j - 1);
      ver[i][j] =
          get(ver, i - 1, j) + get(ver, i, j - 1) - get(ver, i - 1, j - 1);
      if (grid[i][j] == '.' && j != w - 1 && grid[i][j + 1] == '.') {
        hor[i][j]++;
      }
      if (grid[i][j] == '.' && i != h - 1 && grid[i + 1][j] == '.') {
        ver[i][j]++;
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    printf("%d\n", solve_query(hor, ver));
  }
}
int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  solve(h, w);
}
