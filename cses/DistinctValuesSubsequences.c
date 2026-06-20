#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
#define MAX 200005
const ll MOD = 1e9 + 7LL;
typedef struct Node {
  ll key;
  ll freq;
  struct Node *next;
} Node;
typedef struct {
  Node *buckets[MAX];
  ll arr_unq[MAX];
  ll arr_unq_idx;
} HashMap;
void hashmap_init(HashMap *map) {
  memset(map, 0, sizeof(map->buckets));
  map->arr_unq_idx = 0;
}
void map_add(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *target = malloc(sizeof(Node));
  target->freq = 1;
  target->key = key;
  target->next = map->buckets[h];
  map->buckets[h] = target;
  map->arr_unq[map->arr_unq_idx++] = key;
}
void map_inc(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *curr = map->buckets[h];
  while (curr) {
    if (curr->key == key) {
      curr->freq++;
      return;
    }
    curr = curr->next;
  }
  map_add(map, key);
}
ll map_get(HashMap *map, ll key) {
  ll h = key % MAX;
  Node *curr = map->buckets[h];
  while (curr) {
    if (curr->key == key) {
      return curr->freq;
    }
    curr = curr->next;
  }
  return 0;
}
void map_free(HashMap *map) {
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
  HashMap map;
  hashmap_init(&map);
  for (ll i = 0; i < n; i++) {
    ll x;
    scanf("%lld", &x);
    map_inc(&map, x);
  }
  ll total = 1;
  for (ll i = 0; i < map.arr_unq_idx; i++) {
    total *= map_get(&map, map.arr_unq[i]) + 1;
    total %= MOD;
  }
  printf("%lld\n", total - 1);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
