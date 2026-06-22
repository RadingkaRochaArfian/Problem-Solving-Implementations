#include <stdio.h>
#include <stdlib.h>
int isValid(int n, int m, int i, int j) {
  return (i >= 0 && j <= m - 1 && i <= n - 1 && j >= 0);
}
void printInput(char **input, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", input[i][j]);
    }
    printf("\n");
  }
}
void solve(char **input, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int base[256] = {0};
      char ch = input[i][j];
      base[ch] = 1;
      if (isValid(n, m, i - 1, j)) {
        ch = input[i - 1][j];
        base[ch] = 1;
      }
      if (isValid(n, m, i, j - 1)) {
        ch = input[i][j - 1];
        base[ch] = 1;
      }
      int possible = 1;
      for (int k = 0; k < 4; k++) {
        int hash = 'A' + k;
        if (base[hash] == 0) {
          input[i][j] = hash;
          possible = 0;
          break;
        }
      }
      if (possible == 1) {
        printf("IMPOSSIBLE\n");
        return;
      }
    }
  }
  printInput(input, n, m);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  char **input = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    input[i] = (char *)malloc(sizeof(char) * m);
  }
 
  for (int i = 0; i < n; i++) {
    char line[501];
    scanf("%s", line);
    for (int j = 0; j < m; j++) {
      input[i][j] = line[j];
    }
  }
  solve(input, n, m);
  for (int i = 0; i < n; i++) {
    free(input[i]);
  }
  free(input);
}