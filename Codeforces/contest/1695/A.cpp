#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif
const int N = 50;
int a[N][N];

void solve() {
  int n, m; cin >> n >> m;
  array<int, 2> id = {1, 1};
  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> a[i][j];
    }
  }
  rep(i, 1, n) {
    rep(j, 1, m) {
      if(a[i][j] > a[id[0]][id[1]]) {
        id = {i, j};
      }
    }
  }
  int l = max(id[0], n - id[0] + 1);
  int r = max(id[1], m - id[1] + 1);
  cout << l * r << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}