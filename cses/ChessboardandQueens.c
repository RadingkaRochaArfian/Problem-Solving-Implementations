#include <stdio.h>
int savePut(char board[8][8], int r, int c) {
  if (board[r][c] == '*') {
    return 0;
  }
  for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'q')
      return 0;
  }
  for (int i = c - 1; i >= 0; i--) {
    if (board[r][i] == 'q')
      return 0;
  }
  for (int i = r + 1, j = c - 1; i < 8 && j >= 0; i++, j--) {
    if (board[i][j] == 'q')
      return 0;
  }
  return 1;
}
int ans = 0;
void solve(char board[8][8], int c) {
  if (c == 8) {
    ans++;
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (savePut(board, i, c)) {
      board[i][c] = 'q';
      solve(board, c + 1);
      board[i][c] = '.';
    }
  }
}
 
int main() {
  char board[8][8];
  for (int i = 0; i < 8; i++) {
    scanf("%s", board[i]);
  }
  solve(board, 0);
  printf("%d\n", ans);
}