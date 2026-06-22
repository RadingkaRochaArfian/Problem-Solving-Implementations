#include <stdio.h>
#include <stdlib.h>
#define N 7
int isSafe(int i, int j) { return (i >= 0 && i < N && j >= 0 && j < N); }
int dfs(char knownPath[N], int i, int j, int step, int **flag, int sumPath) {
  if (step == N * N - 1 || i == N - 1 && j == 0) {
    sumPath += (step == N * N - 1 && i == N - 1 && j == 0);
    return sumPath;
  }
  if ((!isSafe(i - 1, j) || flag[i - 1][j]) &&
      (!isSafe(i + 1, j) || flag[i + 1][j])) {
    if (isSafe(i, j - 1) && !flag[i][j - 1] && isSafe(i, j + 1) &&
        !flag[i][j + 1]) {
      return sumPath;
    }
  }
  if ((!isSafe(i, j - 1) || flag[i][j - 1]) &&
      (!isSafe(i, j + 1) || flag[i][j + 1])) {
    if (isSafe(i + 1, j) && !flag[i + 1][j] && isSafe(i - 1, j) &&
        !flag[i - 1][j]) {
      return sumPath;
    }
  }
  flag[i][j] = 1;
  if (knownPath[step] == '?' || knownPath[step] == 'L') {
 
    if (isSafe(i, j - 1) && !flag[i][j - 1]) {
      sumPath = dfs(knownPath, i, j - 1, step + 1, flag, sumPath);
    }
  }
  if (knownPath[step] == '?' || knownPath[step] == 'R') {
 
    if (isSafe(i, j + 1) && !flag[i][j + 1]) {
      sumPath = dfs(knownPath, i, j + 1, step + 1, flag, sumPath);
    }
  }
  if (knownPath[step] == '?' || knownPath[step] == 'U') {
 
    if (isSafe(i - 1, j) && !flag[i - 1][j]) {
      sumPath = dfs(knownPath, i - 1, j, step + 1, flag, sumPath);
    }
  }
  if (knownPath[step] == '?' || knownPath[step] == 'D') {
 
    if (isSafe(i + 1, j) && !flag[i + 1][j]) {
      sumPath = dfs(knownPath, i + 1, j, step + 1, flag, sumPath);
    }
  }
  flag[i][j] = 0;
  return sumPath;
}
void solve(char knownPath[49]) {
  int **flag = malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++) {
    flag[i] = malloc(sizeof(int) * N);
    for (int j = 0; j < N; j++) {
      flag[i][j] = 0;
    }
  }
  int sumPath = dfs(knownPath, 0, 0, 0, flag, 0);
  printf("%d\n", sumPath);
}
int main() {
  char knownPath[49];
  knownPath[0] = '\0';
  scanf("%s", knownPath);
  solve(knownPath);
}