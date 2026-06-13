#include <stdio.h>
#include <string.h>
#define MAX_SIZE 201
#define OFFSET 100
typedef long long ll;
int get_d_idx(char c) {
  switch (c) {
  case 'L':
    return 0;
  case 'R':
    return 1;
  case 'U':
    return 2;
  case 'D':
    return 3;
  default:
    return -1;
  }
}
int is_multiple_neighbour(int arr_vis[MAX_SIZE][MAX_SIZE], int *di, int *dj,
                          int d_i, int d_j, int i, int j) {
  for (ll k = 0; k < 4; k++) {
    int ni = d_i + di[k];
    int nj = d_j + dj[k];
    if (ni == i && nj == j)
      continue;
    if (arr_vis[ni][nj]) {
      return 1;
    }
  }
  return 0;
}
void solve(int di[], int dj[]) {
  char s[OFFSET];
  scanf("%s", s);
  ll n = strlen(s);
  int arr_vis[MAX_SIZE][MAX_SIZE] = {0};
  int i = OFFSET;
  int j = OFFSET;
  arr_vis[i][j] = 1;
  int flag = 0;
  for (ll k = 0; k < n; k++) {
    int d_idx = get_d_idx(s[k]);
    int d_i = i + di[d_idx];
    int d_j = j + dj[d_idx];
    if (arr_vis[d_i][d_j]) {
      printf("BUG\n");
      return;
    }
    if (is_multiple_neighbour(arr_vis, di, dj, d_i, d_j, i, j)) {
      printf("BUG\n");
      return;
    }
    i = d_i;
    j = d_j;
    arr_vis[i][j] = 1;
  }
  printf("OK\n");
}
int main() {
  int di[] = {0, 0, -1, 1};
  int dj[] = {-1, 1, 0, 0};
  solve(di, dj);
}
