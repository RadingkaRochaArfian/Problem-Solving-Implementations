#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int see(int target, int visA[], int a[], int n) {
  int l = 0, r = n - 1, cnt = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (!visA[mid] && a[mid] >= target) {
      visA[mid] = 1;
      if (a[mid] == target) {
        return 1;
      }
      cnt++;
      break;
    } else if (visA[mid] || a[mid] < target) {
      l = mid + 1;
    } else if (a[mid] > target) {
      r = mid - 1;
    }
  }
  l = 0, r = n - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (!visA[mid] && a[mid] < target) {
      visA[mid] = 1;
      cnt++;
      break;
    } else if (visA[mid] || a[mid] > target) {
      r = mid - 1;
    }
  }
  if (cnt == 2) {
    return 1;
  } else {
    return 0;
  }
}
int see2(int target, int visA[], int a[], int n) {
  int mid = (n - 1) / 2;
  int cnt = 0;
  for (int i = mid; i < n; i++) {
    if (!visA[i] && a[i] >= target) {
      visA[i] = 1;
      if (a[i] == target) {
        return 1;
      }
      cnt++;
      break;
    }
  }
  for (int i = mid; i >= 0; i--) {
    if (!visA[i] && a[i] < target) {
      visA[i] = 1;
      cnt++;
      break;
    }
  }
  if (cnt == 2) {
    return 1;
  } else {
    return 0;
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  int visA[n];
  for (int i = 0; i < n; i++) {
    visA[i] = 0;
  }
  int canB[m];
  for (int i = 0; i < m; i++) {
    canB[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  reverse(b, b + m);
  for (int i = 0; i < m; i++) {
    if (i != m - 1)
      canB[i] = see(b[i], visA, a, n);
    else
      canB[i] = see2(b[i], visA, a, n);
  }
  int can = 1;
  for (int i = 0; i < m; i++) {
    if (canB[i] == 0) {
      can = 0;
    }
  }
  if (can == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
