#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
int maxNode;
vector<bool> notAllowed;
vector<int> must;
vector<vector<int>> mustDistByChar, parents;
int l, m, f;
int step(int mantra, int addBit) {
  int addedMantra = (mantra << 1) | addBit;
  if (notAllowed[addedMantra]) {
    return -1;
  }
  return addedMantra & (maxNode - 1);
}
void bfs(int mantra, int idx) {
  vector<int> currDist(maxNode, INT_MAX);
  vector<int> currParents(maxNode, -2);
  queue<int> q;
  currDist[mantra] = 0;
  currParents[mantra] = -1;
  q.push(mantra);
  while (!q.empty()) {
    int currMantra = q.front();
    q.pop();
    for (int i = 0; i < 2; i++) {
      int newMantra = step(currMantra, i);
      if (newMantra == -1) {
        continue;
      }
      if (currDist[newMantra] == INT_MAX) {
        currDist[newMantra] = currDist[currMantra] + 1;
        currParents[newMantra] = currMantra;
        q.push(newMantra);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    mustDistByChar[idx][i] = currDist[must[i]];
  }
  parents[idx] = currParents;
}
string addChar(int idxFrom, int mantraFrom, int mantraTo) {
  vector<int> &currParents = parents[idxFrom];
  vector<int> arrMantra;
  int currMantra = mantraTo;
  while (currMantra != mantraFrom) {
    arrMantra.push_back(currMantra);
    currMantra = currParents[currMantra];
  }
  reverse(arrMantra.begin(), arrMantra.end());
  string res;
  for (int mantra : arrMantra) {
    int c = mantra & 1;
    res += char('0' + c);
  }
  return res;
}
int main() {
  cin >> l >> m >> f;
  must.assign(m, 0);
  maxNode = 1 << l;
  notAllowed.assign(1 << (l + 1), false);
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    int v = 0;
    for (char c : s) {
      v = (v << 1) | (c - '0');
    }
    must[i] = v;
  }
  for (int i = 0; i < f; i++) {
    string s;
    cin >> s;
    int v = 0;
    for (char c : s) {
      v = (v << 1) | (c - '0');
    }
    notAllowed[v] = true;
  }
  mustDistByChar.assign(m, vector<int>(m, INT_MAX));
  parents.assign(m, vector<int>());
  for (int i = 0; i < m; i++) {
    bfs(must[i], i);
  }
  int maxVisitIdx = 1 << m;
  vector<vector<ll>> dp(maxVisitIdx, vector<ll>(m, LLONG_MAX / 2));
  vector<vector<int>> parentDp(maxVisitIdx, vector<int>(m, -1));
  for (int i = 0; i < m; i++) {
    dp[1 << i][i] = 0;
  }
  for (int visitedIdx = 1; visitedIdx < maxVisitIdx; visitedIdx++) {
    for (int i = 0; i < m; i++) {
      if (!((visitedIdx >> i) & 1)) {
        continue;
      }
      if (dp[visitedIdx][i] >= LLONG_MAX / 2) {
        continue;
      }
      for (int j = 0; j < m; j++) {
        if ((visitedIdx >> j) & 1) {
          continue;
        }
        if (mustDistByChar[i][j] == INT_MAX) {
          continue;
        }
        int moreVisitedIdx = visitedIdx | (1 << j);
        ll lenFromParentNode = dp[visitedIdx][i] + mustDistByChar[i][j];
        if (lenFromParentNode < dp[moreVisitedIdx][j]) {
          dp[moreVisitedIdx][j] = lenFromParentNode;
          parentDp[moreVisitedIdx][j] = i;
        }
      }
    }
  }
  ll bestLenFromParentNode = LLONG_MAX / 2;
  ll bestLastIdx = -1;
  for (int i = 0; i < m; i++) {
    if (dp[maxVisitIdx - 1][i] < bestLenFromParentNode) {
      bestLenFromParentNode = dp[maxVisitIdx - 1][i];
      bestLastIdx = i;
    }
  }
  if (bestLastIdx == -1 || bestLenFromParentNode == LLONG_MAX / 2) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> idxOrder;
  int idxNeedVisit = maxVisitIdx - 1;
  int currIdx = bestLastIdx;
  while (currIdx != -1) {
    idxOrder.push_back(currIdx);
    int parentIdx = parentDp[idxNeedVisit][currIdx];
    idxNeedVisit ^= (1 << currIdx);
    currIdx = parentIdx;
  }
  reverse(idxOrder.begin(), idxOrder.end());
  string ans;
  for (int i = 0; i < l; i++) {
    ans += char('0' + ((must[idxOrder[0]] >> (l - 1 - i)) & 1));
  }
  for (int i = 0; i + 1 < idxOrder.size(); i++) {
    int idxFrom = idxOrder[i];
    int idxTo = idxOrder[i + 1];
    ans += addChar(idxFrom, must[idxFrom], must[idxTo]);
  }
  cout << ans << endl;
}
