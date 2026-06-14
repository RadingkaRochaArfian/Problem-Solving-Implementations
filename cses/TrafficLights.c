#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
#define MAX_OP 200005
typedef struct Node {
  ll val;
  ll count;
  ll h;
  struct Node *l, *r;
} Node;
Node *create_node(ll val) {
  Node *nd = (Node *)malloc(sizeof(Node));
  nd->val = val;
  nd->count = 1;
  nd->h = 1;
  nd->l = nd->r = NULL;
  return nd;
}

ll bst_max(Node *root) {
  while (root->r) {
    root = root->r;
  }
  return root->val;
}
ll find_predessor(Node *nd, ll p) {
  ll res = -1;
  while (nd) {
    if (nd->val < p) {
      res = nd->val;
      nd = nd->r;
    } else {
      nd = nd->l;
    }
  }
  return res;
}
ll find_successor(Node *nd, ll p) {
  ll res = -1;
  while (nd) {
    if (nd->val > p) {
      res = nd->val;
      nd = nd->l;
    } else {
      nd = nd->r;
    }
  }
  return res;
}
ll get_h(Node *nd) { return nd ? nd->h : 0; }
ll find_max(ll a, ll b) { return a > b ? a : b; }
void update_h(Node *nd) {
  if (nd) {
    nd->h = 1 + find_max(get_h(nd->l), get_h(nd->r));
  }
}
Node *rot_right(Node *nd) {
  Node *leaf_l = nd->l, *leaf_r = leaf_l->r;
  leaf_l->r = nd;
  nd->l = leaf_r;
  update_h(nd);
  update_h(leaf_l);
  return leaf_l;
}
Node *rot_left(Node *nd) {
  Node *leaf_r = nd->r, *leaf_l = leaf_r->l;
  leaf_r->l = nd;
  nd->r = leaf_l;
  update_h(nd);
  update_h(leaf_r);
  return leaf_r;
}
ll leaf_h_diff(Node *nd) { return nd ? (get_h(nd->l) - get_h(nd->r)) : 0; }
Node *balance(Node *nd) {
  update_h(nd);
  ll h_diff = leaf_h_diff(nd);
  if (h_diff > 1) {
    if (leaf_h_diff(nd->l) < 0) {
      nd->l = rot_left(nd->l);
    }
    return rot_right(nd);
  }
  if (h_diff < -1) {
    if (leaf_h_diff(nd->r) > 0) {
      nd->r = rot_right(nd->r);
    }
    return rot_left(nd);
  }
  return nd;
}
Node *erase_val(Node *root, ll val) {
  if (!root)
    return NULL;
  if (val < root->val) {
    root->l = erase_val(root->l, val);
  } else if (val > root->val) {
    root->r = erase_val(root->r, val);
  } else {
    if (root->count > 1) {
      root->count--;
      return root;
    }
    if (!root->l) {
      Node *r = root->r;
      free(root);
      return r;
    } else if (!root->r) {
      Node *l = root->l;
      free(root);
      return l;
    } else {
      Node *target = root->r;
      while (target->l) {
        target = target->l;
      }
      root->val = target->val;
      root->count = target->count;
      target->count = 1;
      root->r = erase_val(root->r, root->val);
    }
  }
  return balance(root);
}
Node *insert(Node *root, ll val) {
  if (!root) {
    return create_node(val);
  }
  if (val < root->val) {
    root->l = insert(root->l, val);
  } else if (val > root->val) {
    root->r = insert(root->r, val);
  } else {
    root->count++;
    return root;
  }
  return balance(root);
}
void solve(Node **pos, Node **node_len) {
  ll p;
  scanf("%lld", &p);
  ll l = find_predessor(*pos, p);
  ll r = find_successor(*pos, p);
  *node_len = erase_val(*node_len, r - l);
  *node_len = insert(*node_len, p - l);
  *node_len = insert(*node_len, r - p);
  ll max_val = bst_max(*node_len);
  *pos = insert(*pos, p);
  printf("%lld ", max_val);
}
int main() {
  ll x, n;
  scanf("%lld %lld", &x, &n);
  Node *pos = NULL;
  pos = insert(pos, 0);
  pos = insert(pos, x);
  Node *node_len = NULL;
  ll max_val = 0;
  node_len = insert(node_len, x);
  for (ll i = 0; i < n; i++) {
    solve(&pos, &node_len);
  }
  printf("\n");
}
