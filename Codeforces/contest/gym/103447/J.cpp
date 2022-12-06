#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e3 + 10;

int n;
ll a[N][N];
ll row[N], col[N];
void solve() {
  int n, m; cin >> n >> m;
  memset(row, 0x3f, sizeof row);
  memset(col, 0x3f, sizeof col);
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      cin >> a[i][j];
      row[i] = min(row[i], a[i][j]);
      col[j] = min(col[j], a[i][j]);
      
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      if(a[i][j] == row[i] && a[i][j] == col[j]) {
        ans ++;
      }
    }
  }
  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();

  return 0;
}