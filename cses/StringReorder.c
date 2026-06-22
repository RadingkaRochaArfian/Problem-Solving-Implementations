#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPossible(int map[26], char cur) {
  char mode = cur;
  int totalLeft = 0;
  for (int i = 0; i < 26; i++) {
    char ch = 'A' + i;
    int sumNow = map[ch - 'A'];
    if (sumNow > map[mode - 'A'])
      mode = ch;
    totalLeft += sumNow;
  }
  return map[mode - 'A'] <= (totalLeft + 1) / 2;
}
void solve(char s[1000006], int n) {
  int map[26];
  for (int i = 0; i < 26; i++) {
    map[i] = 0;
  }
  char *line = malloc(sizeof(char) * (n + 1));
  int lineLen = 0;
  line[0] = '\0';
  char last = '\0';
  for (int i = 0; i < n; i++) {
 
    map[s[i] - 'A']++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      char ch = 'A' + j;
      if (map[ch - 'A'] == 0 || ch == last) {
        continue;
      }
      map[ch - 'A']--;
      if (isPossible(map, ch)) {
        line[lineLen++] = ch;
        line[lineLen] = '\0';
        last = ch;
        break;
      } else {
        map[ch - 'A']++;
      }
    }
  }
  if (strlen(line) == n) {
    printf("%s\n", line);
  } else {
    printf("-1\n");
  }
  free(line);
}
int main() {
 
  char s[1000006];
  scanf("%s", s);
  int n = strlen(s);
  solve(s, n);
}