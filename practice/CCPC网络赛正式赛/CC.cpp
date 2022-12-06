#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= b; ++ i)

int f[100][100];

int dfs(int x, int y) {
  return x / 2 + 1;
}

void solve() {
  ll a, b; cin >> a >> b;
  int x = 0, y = 0;
  while (~a & 1) { a >>= 1; x ++ ; }
  while (~b & 1) { b >>= 1; y ++ ; }
  
  if (x < y) {
    cout << dfs(x, y) << " " << 1;
  } else {
    cout << dfs(x, y) << " " << 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(f, -1, sizeof f);
  f[0][1] = 1; f[1][0] = 1;
  f[1][2] = 1; f[2][1] = 2;
  f[2][3] = 2; f[3][2] = 2;
  int T; cin >> T;
  for (int i = 1; i <= T; i ++ ) {
    solve();
    if (i != T) cout << "\n";
  }
  return 0;
}