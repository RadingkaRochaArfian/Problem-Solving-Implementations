#include <stdio.h>
#include <string.h>
 
typedef struct {
  char key;
  int value;
  int terisi;
} hashmap;
 
hashmap map[26];
void map_init() {
  for (int i = 0; i < 26; i++) {
    map[i].terisi = 0;
    map[i].value = 0;
  }
}
int hash_char(char c) { return c - 'a'; }
void map_put(char key, int value) {
  int indeks = hash_char(key);
  map[indeks].key = key;
  map[indeks].value = value;
  map[indeks].terisi = 1;
}
int *map_get(char key) {
  int indeks = hash_char(key);
  if (map[indeks].terisi && map[indeks].key == key) {
    return &map[indeks].value;
  }
  return NULL;
}
void map_remove(char key) {
  int indeks = hash_char(key);
  map[indeks].terisi = 0;
  map[indeks].value = 0;
}
int fact(int n) {
  int x = 1;
  for (int i = 1; i <= n; i++) {
    x *= i;
  }
  return x;
}
void print_permutasi(char buffer[], int n, int giliran) {
  if (giliran == n) {
    buffer[giliran] = '\0';
    printf("%s\n", buffer);
    return;
  }
  for (int i = 0; i < 26; i++) {
    if (map[i].terisi && map[i].value > 0) {
      char ch = 'a' + i;
      buffer[giliran] = ch;
      map[i].value--;
      print_permutasi(buffer, n, giliran + 1);
      map[i].value++;
    }
  }
}
void solve_freqmap(char s[]) {
  int n = strlen(s);
  map_init();
  for (int i = 0; i < n; i++) {
    int indeks = hash_char(s[i]);
    if (!map[indeks].terisi) {
      map_put(s[i], 1);
    } else {
      map[indeks].value++;
    }
  }
  int pembilang = fact(n);
  int penyebut = 1;
  for (int i = 0; i < 26; i++) {
    if (map[i].terisi) {
      penyebut *= fact(map[i].value);
    }
  }
  printf("%d\n", (pembilang / penyebut));
  char buffer[9];
  print_permutasi(buffer, n, 0);
}
void solve() {
  char s[9];
  scanf("%s", s);
  solve_freqmap(s);
}
int main() { solve(); }