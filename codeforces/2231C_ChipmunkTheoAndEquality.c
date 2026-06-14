#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
#define HASH_SIZE 100005
typedef struct Node {
  ll key;
  ll freq;
  ll step;
  struct Node *next;
} Node;
typedef struct {
  Node *buckets[HASH_SIZE];
} HashMap;
void hashmap_init(HashMap *map) {
  memset(map->buckets, 0, sizeof(map->buckets));
}
void hashmap_free(HashMap *map) {
  for (ll i = 0; i < HASH_SIZE; i++) {
    Node *curr = map->buckets[i];
    while (curr) {
      Node *next = curr->next;
      free(curr);
      curr = next;
    }
    map->buckets[i] = NULL;
  }
}
void hashmap_add(HashMap *map, ll key, ll add_freq, ll add_step) {
  ll h = key % HASH_SIZE;
  Node *cur = map->buckets[h];
  while (cur) {
    if (cur->key == key) {
      cur->freq += add_freq;
      cur->step += add_step;
      return;
    }
    cur = cur->next;
  }
  Node *baru = malloc(sizeof(Node));
  baru->freq = add_freq;
  baru->step = add_step;
  baru->key = key;
  baru->next = map->buckets[h];
  map->buckets[h] = baru;
}
ll hashmap_get_freq(HashMap *map, ll key) {
  ll h = key % HASH_SIZE;
  Node *curr = map->buckets[h];
  while (curr) {
    if (curr->key == key) {
      return curr->freq;
    }
    curr = curr->next;
  }
  return 0;
}
void get_op(HashMap *map, ll x, ll flag) {
  ll step = 0;
  ll arr_vis[HASH_SIZE];
  ll arr_vis_idx = 0;
  while (1) {
    for (ll i = 0; i < arr_vis_idx; i++) {
      if (arr_vis[i] == x)
        return;
    }
    arr_vis[(arr_vis_idx)++] = x;
    if (flag || hashmap_get_freq(map, x) > 0) {
      hashmap_add(map, x, 1, step);
    }
    // if (x == 1)
    //   return;
    if (x % 2 == 1) {
      x++;
    } else {
      x /= 2;
    }
    step++;
  }
}
void solve() {
  ll n;
  scanf("%lld", &n);
  ll arr[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  HashMap map;
  hashmap_init(&map);
  for (ll i = 0; i < n; i++) {
    get_op(&map, arr[i], i == 0);
  }
  ll ans = 1e18;
  for (ll i = 0; i < HASH_SIZE; i++) {
    Node *curr = map.buckets[i];
    while (curr) {
      if (curr->freq == n && curr->step < ans) {
        ans = curr->step;
      }
      curr = curr->next;
    }
  }
  printf("%lld\n", ans);
  hashmap_free(&map);
}
int main() {
  ll t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
