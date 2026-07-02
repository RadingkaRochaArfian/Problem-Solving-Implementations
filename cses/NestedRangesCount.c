#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
typedef struct {
  ll start;
  ll end;
  ll idx;
} Range;
void mergeRange(Range arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  Range l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i].start < r[j].start) {
      arr[k++] = l[i++];
    } else if (r[j].start < l[i].start) {
      arr[k++] = r[j++];
    } else {
      if (l[i].end > r[j].end) {
        arr[k++] = l[i++];
      } else {
        arr[k++] = r[j++];
      }
    }
  }
  while (i < n1) {
    arr[k++] = l[i++];
  }
  while (j < n2) {
    arr[k++] = r[j++];
  }
}
void sortRange(Range arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sortRange(arr, left, mid);
    sortRange(arr, mid + 1, right);
    mergeRange(arr, left, mid, right);
  }
}
void mergeEnd(ll arr[], ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  ll l[n1], r[n2];
  for (ll i = 0; i < n1; i++) {
    l[i] = arr[left + i];
  }
  for (ll i = 0; i < n2; i++) {
    r[i] = arr[mid + i + 1];
  }
  ll i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (l[i] < r[j]) {
      arr[k++] = l[i++];
    } else {
      arr[k++] = r[j++];
    }
  }
  while (i < n1) {
    arr[k++] = l[i++];
  }
  while (j < n2) {
    arr[k++] = r[j++];
  }
}
void sortEnd(ll arr[], ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    sortEnd(arr, left, mid);
    sortEnd(arr, mid + 1, right);
    mergeEnd(arr, left, mid, right);
  }
}
ll compressValues(ll arr[], ll n) {
  sortEnd(arr, 0, n - 1);
  ll unqSize = 0;
  for (ll i = 0; i < n; i++) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      arr[unqSize++] = arr[i];
    }
  }
  return unqSize;
}
typedef struct {
  ll *tree;
  ll size;
} BitIndexingTree;
BitIndexingTree *createBit(ll size) {
  BitIndexingTree *bit = malloc(sizeof(BitIndexingTree));
  bit->tree = calloc(size + 1, sizeof(ll));
  bit->size = size;
  return bit;
}
void freeBit(BitIndexingTree *bit) {
  if (bit) {
    free(bit->tree);
    free(bit);
  }
}
ll getCompressedIndex(ll arr[], ll unqSize, ll val) {
  ll left = 0;
  ll right = unqSize - 1;
  while (left <= right) {
    ll mid = left + (right - left) / 2;
    if (arr[mid] == val)
      return mid;
    if (arr[mid] < val)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}
ll bitFind(BitIndexingTree *bit, ll idx) {
  ll sum = 0;
  while (idx > 0) {
    sum += bit->tree[idx];
    idx -= idx & -idx;
  }
  return sum;
}
void bitUpdate(BitIndexingTree *bit, ll idx1, ll val) {
  while (idx1 <= bit->size) {
    bit->tree[idx1] += val;
    idx1 += idx1 & -idx1;
  }
}
void solve(ll n) {
  Range arrRange[n];
  ll arrEnd[n];
  for (ll i = 0; i < n; i++) {
    scanf("%lld %lld", &arrRange[i].start, &arrRange[i].end);
    arrRange[i].idx = i;
    arrEnd[i] = arrRange[i].end;
  }
  sortRange(arrRange, 0, n - 1);
  ll uniqueSize = compressValues(arrEnd, n);
  ll *arrA = calloc(n, sizeof(ll));
  ll *arrB = calloc(n, sizeof(ll));
  BitIndexingTree *bitB = createBit(uniqueSize);
  for (ll i = 0; i < n; i++) {
    ll idx = getCompressedIndex(arrEnd, uniqueSize, arrRange[i].end);
    ll notContainIt = bitFind(bitB, idx);
    arrB[arrRange[i].idx] = i - notContainIt;
    bitUpdate(bitB, idx + 1, 1LL);
  }
  BitIndexingTree *bitA = createBit(uniqueSize);
  for (ll i = n - 1; i >= 0; i--) {
    ll idx = getCompressedIndex(arrEnd, uniqueSize, arrRange[i].end);
    ll containsByIt = bitFind(bitA, idx + 1);
    arrA[arrRange[i].idx] = containsByIt;
    bitUpdate(bitA, idx + 1, 1LL);
  }
  for (ll i = 0; i < n; i++) {
    printf("%lld", arrA[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
  for (ll i = 0; i < n; i++) {
    printf("%lld", arrB[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
  freeBit(bitA);
  freeBit(bitB);
  free(arrA);
  free(arrB);
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
