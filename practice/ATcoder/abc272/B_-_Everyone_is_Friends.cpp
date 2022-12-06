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

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int> > a(m);
  set<int> s[110];
  for (int i = 0; i < m; i ++ ) {
    int k; cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; j ++ ) {
      cin >> a[i][j];
      s[a[i][j]].insert(i);
    }
  }
  bool flag = true;
  for (int i = 1; i <= n; i ++ ) {
    set<int> S;
    for (int id: s[i]) {
      for (int j = 0; j < a[id].size(); j ++ ) {
        S.insert(a[id][j]);
      }
    }
    if ((int)S.size() != n) {
      flag = false;
      break;
    }
  }
  cout << (flag ?  "Yes" : "No");
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}