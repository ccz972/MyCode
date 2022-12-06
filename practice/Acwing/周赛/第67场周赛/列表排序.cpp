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

int a[30][30];
int cnt[30];

void solve() {
  int n, m; cin >> n >> m;
  int leagl = 0;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      cin >> a[i][j];
      cnt[i] += (a[i][j] != j);
    }
    leagl += (cnt[i] <= 2);
    if (cnt[i] > 4) {
      cout << "NO\n";
      return ;
    }
  }

  if (leagl == n) {
    cout << "YES\n";
    return ;
  }
  set<int> s1, s2;
  for (int j = 1; j <= m; j ++ ) {
    int now = 0;
    for (int i = 1; i <= n; i ++ ) if (a[i][j] != j) {
      ++ now;
    }
    if (now == n - leagl) {
      s1.insert(j);
    } else {
      s2.insert(j);
    }
  }

  int sz1 = s1.size(), sz2 = s2.size();
  
  if (sz1 + sz2 > min(m, 4)) {
    cout << "NO\n";
    return ;
  }

  puts("?");
  

  switch (sz1) {
  case 0 :
    cout << "NO\n";
    break;
  case 1 :
    if (sz2 <= 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    break;
  case 2 :
    if (sz2 <= 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    break;
  
  default:
    cout << "NO\n";
    break;
  }


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}