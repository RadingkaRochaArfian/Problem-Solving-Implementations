    #include <stdio.h>
    #include <string.h>
    typedef long long ll;
    void solve() {
      ll n, m;
      scanf("%lld %lld", &n, &m);
      ll row[n], col[m];
      memset(row, 0, n * sizeof(ll));
      memset(col, 0, m * sizeof(ll));
      char mat[n][m];
      for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
          scanf(" %c", &mat[i][j]);
          row[i] += (mat[i][j] == '.');
          col[j] += (mat[i][j] == '.');
        }
      }
      ll ans = n + m;
      for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
          ans = (ans > (row[i] + col[j] - (mat[i][j] == '.')))
                    ? (row[i] + col[j] - (mat[i][j] == '.'))
                    : ans;
        }
      }
      printf("%lld\n", ans);
    }
    int main() {
      ll t;
      scanf("%lld", &t);
      while (t--) {
        solve();
      }
    }

