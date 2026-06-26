#include <stdlib.h>
typedef long long ll;
#define MAX 20000007

typedef struct Node {
  ll key;
  ll value;
  struct Node *next;
} Node;

typedef struct {
  Node *buckets[MAX];
} Map;

void initMap(Map *map) {
  for (int i = 0; i < MAX; i++) {
    map->buckets[i] = NULL;
  }
}

int hash(ll key) { return key % MAX; }

Node *createNode(ll key, ll value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insertMapValue(Map *map, ll key, ll value) {
  int index = hash(key);
  Node *head = map->buckets[index];

  Node *temp = head;
  while (temp != NULL) {
    if (temp->key == key) {
      temp->value = value;
      return;
    }
    temp = temp->next;
  }

  Node *newNode = createNode(key, value);
  newNode->next = head;
  map->buckets[index] = newNode;
}

void freeMap(Map *map) {
  if (map == NULL)
    return;

  for (int i = 0; i < MAX; i++) {
    Node *current = map->buckets[i];
    while (current != NULL) {
      Node *next = current->next;
      free(current);
      current = next;
    }
  }

  free(map);
}

int main() {
  Map *map = (Map *)malloc(sizeof(Map));
  initMap(map);
  freeMap(map);
}
