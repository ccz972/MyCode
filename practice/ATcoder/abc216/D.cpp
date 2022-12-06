#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, m; 
  cin >> n >> m;
  vector<vector<int> > a(m);
  for (int i = 0; i < m; i ++ ) {
    int k; cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; j ++ ) {
      cin >> a[i][j];
    }
  }

  vector<int> idx(n + 1, -1);
  vector<int> now(m, 0);

  function<void(int, int)> dfs = [&] (int i, int j) {
    if (idx[a[i][j]] == -1) {
      idx[a[i][j]] = i;
    } else if(idx[a[i][j]] >= 0) {
      auto x = idx[a[i][j]];
      idx[a[i][j]] = -2;
      if (now[x] != a[x].size()) {
        dfs (x, now[x] ++);
      }
      if (now[i] != a[i].size()) {
        dfs (i, now[i] ++ );
      }
    }
  };

  for (int i = 0; i < m; i ++ ) {
    if (now[i] != a[i].size()) {
      dfs (i, now[i] ++ );
    }
  }

  for (int i = 0; i < m; i ++ ) {
    if (now[i] != a[i].size()) {
      cout << "No\n";
      return ;
    }
  }

  cout << "Yes\n";






}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}