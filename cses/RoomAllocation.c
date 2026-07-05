#include <stdio.h>
#define MAXN 200005
typedef long long ll;
typedef struct {
  ll start;
  ll end;
  ll idx;
} Interval;
void sort(Interval *arr, ll left, ll mid, ll right) {
  ll n1 = mid - left + 1;
  ll n2 = right - mid;
  Interval l[n1], r[n2];
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
void mergeSort(Interval *arr, ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    sort(arr, left, mid, right);
  }
}
typedef struct {
  ll end;
  ll id1;
} Room;
void sortUpHeap(Room arr[], ll targetIdx) {
  if (targetIdx <= 0)
    return;
  ll parentIdx = (targetIdx - 1) / 2;
  if (arr[parentIdx].end <= arr[targetIdx].end)
    return;
  Room temp = arr[parentIdx];
  arr[parentIdx] = arr[targetIdx];
  arr[targetIdx] = temp;
  sortUpHeap(arr, parentIdx);
}
void pushHeap(Room arr[], ll *idx, Room input) {
  arr[*idx] = input;
  (*idx)++;
  ll addedIdx = (*idx) - 1;
  sortUpHeap(arr, addedIdx);
}
void sortDownHeap(Room arr[], ll size, ll targetIdx) {
  ll minIdx = targetIdx;
  ll left = 2 * targetIdx + 1;
  ll right = 2 * targetIdx + 2;
  if (left < size && arr[left].end < arr[minIdx].end) {
    minIdx = left;
  }
  if (right < size && arr[right].end < arr[minIdx].end) {
    minIdx = right;
  }
  if (minIdx != targetIdx) {
    Room temp = arr[targetIdx];
    arr[targetIdx] = arr[minIdx];
    arr[minIdx] = temp;
    sortDownHeap(arr, size, minIdx);
  }
}
void popHeap(Room arr[], ll *idx) {
  arr[0] = arr[*idx - 1];
  (*idx)--;
  sortDownHeap(arr, *idx, 0);
}
void solve(ll n) {
  Interval arrInterval[MAXN];
  for (ll i = 0; i < n; i++) {
    scanf("%lld %lld", &arrInterval[i].start, &arrInterval[i].end);
    arrInterval[i].idx = i;
  }
  mergeSort(arrInterval, 0, n - 1);
  ll arrRoomPrint[MAXN];
  Room arrRoom[MAXN];
  ll arrRoomIdx = 0;
  arrRoomPrint[arrInterval[0].idx] = 1;
  Room firstRoom = {arrInterval[0].end, 1};
  pushHeap(arrRoom, &arrRoomIdx, firstRoom);
  for (ll i = 1; i < n; i++) {
    ll start = arrInterval[i].start;
    ll end = arrInterval[i].end;
    ll idx = arrInterval[i].idx;
    ll minEnd = arrRoom[0].end;
    ll id1 = arrRoom[0].id1;
    if (minEnd < start) {
      popHeap(arrRoom, &arrRoomIdx);
      arrRoomPrint[idx] = id1;
      Room newRoom = {end, id1};
      pushHeap(arrRoom, &arrRoomIdx, newRoom);
    } else {
      arrRoomPrint[idx] = arrRoomIdx + 1;
      Room newRoom = {end, arrRoomPrint[idx]};
      pushHeap(arrRoom, &arrRoomIdx, newRoom);
    }
  }
  ll maxRoom = 0;
  for (ll i = 0; i < n; i++) {
    if (arrRoomPrint[i] > maxRoom) {
      maxRoom = arrRoomPrint[i];
    }
  }
  printf("%lld\n", maxRoom);
  for (ll i = 0; i < n; i++) {
    printf("%lld", arrRoomPrint[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
}
int main() {
  ll n;
  scanf("%lld", &n);
  solve(n);
}
