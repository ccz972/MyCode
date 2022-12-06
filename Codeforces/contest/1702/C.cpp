#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    map<int, int> l, r;
    for(int i = 0; i < n; i ++ ) {
      cin >> a[i];
      if(!l.count(a[i])) {
        l[a[i]] = i + 1;
      } 
      r[a[i]] = i + 1;
    }

    while(m -- ) {
      int x, y; cin >> x >> y;
      if(!l.count(x) || !l.count(y)) {
        cout << "NO\n";
      } else {
        if(l[x] < r[y]) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      }
    } 
  }
  return 0;
}