#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define rep(i, a, b) for (int i(a); i <= (b); i ++ )
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define all(a) a.begin(), a.end()

constexpr int N = 1010;

int n; 
int a[N][N];

void solve() {
  cin >> n;  
  int cnt_zero = 0;
  int x, y;
  rep(i, 1, n) rep(j, 1, n) {
    cin >> a[i][j];
    if (a[i][j] == -1) {
      x = i, y = j;
    }
  }

  if (x == 1 && y == 1) {
    ll ans = a[x + 1][y] + a[x][y + 1] - a[x + 1][y + 1];
    cout << ans << "\n";
  } else if (x == 1 && y == n) {
    ll ans = a[x + 1][y] + a[x][y - 1] - a[x + 1][y - 1];
    cout << ans << "\n";
  } else if (x == n && y == 1) {
    ll ans = a[x - 1][y] + a[x][y + 1] - a[x - 1][y + 1];
    cout << ans << "\n";
  } else {
    ll ans = a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1];
    cout << ans << "\n";
  } 
  
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}