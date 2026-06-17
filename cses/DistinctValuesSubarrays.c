#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20000007
typedef long long ll;
typedef struct Node {
  ll key;
  ll val;
  struct Node *next;
} Node;
typedef struct {
  Node *buckets[MAX];
} HashMap;
void hashmap_init(HashMap *map) { memset(map, 0, sizeof(map->buckets)); }
ll get_val(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *curr = map->buckets[h];
  while (curr) {
    if (curr->key == key) {
      return curr->val;
    }
  }
  return 0;
}
void add_val(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *nd = malloc(sizeof(Node));
  nd->key = key;
  nd->val = 1;
  nd->next = map->buckets[h];
  map->buckets[h] = nd;
}
void inc_val(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *curr = map->buckets[h];
  while (curr) {
    if (curr->key == key) {
      curr->val++;
      return;
    }
    curr = curr->next;
  }
  add_val(map, key);
}
void dec_val(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *curr = map->buckets[h];
  while (curr) {
    if (curr->key == key) {
      curr->val--;
      return;
    }
    curr = curr->next;
  }
}
void free_map(HashMap *map) {
  for (ll i = 0; i < MAX; i++) {
    Node *curr = map->buckets[i];
    while (curr) {
      Node *next = curr->next;
      free(curr);
      curr = next;
    }
    map->buckets[i] = NULL;
  }
}
void solve(ll n) {
  ll i = 0, j = 0;
  ll arr[n];
  HashMap map;
  hashmap_init(&map);
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  ll ans = 0;
  while (j < n) {
    inc_val(&map, arr[j]);
    while (get_val(&map, arr[j]) > 1) {
      dec_val(&map, arr[i]);
      i++;
    }
    ans += j - i + 1;
    j++;
  }
  free_map(&map);
  printf("%lld\n", ans);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
