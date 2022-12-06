#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

ll __stol(string s, ll ret = 0) {
  for (char c: s) {
    ret = ret * 10 + (c - '0');
  }
  // cout << s << " " << ret << "\n";
  return ret ;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> a;
  vector<char> b;

  for (int i = 1; i <= n; i ++ ) {
    string s; cin >> s;
    string t; int j = -1; while (s[j + 1] && isdigit(s[j + 1])) ++ j, t += s[j];
    if (a.empty() || b.back() != s.back()) {
      a.push_back(__stol(t));
      b.push_back(s.back());
    } else {
      a.back() += __stol(t);
    }
  }

  vector<ll> x;
  vector<char> y;

  for (int i = 1; i <= m; i ++ ) {
    string s; cin >> s;
    string t; int j = -1; while (s[j + 1] && isdigit(s[j + 1])) ++ j, t += s[j];
    if (x.empty() || y.back() != s.back()) {
      x.push_back(__stol(t));
      y.push_back(s.back());
    } else {
      x.back() += __stol(t);
    }
  }

  n = a.size(), m = x.size();

  ll ans = 0;

  if (m == 1) {
    for (int i = 0; i < n; i ++ ) if (a[i] >= x[0] && b[i] == y[0]) {
      ans += (a[i] - x[0] + 1);
    }
    return cout << ans << "\n", void(); 
  }

  vector<int> ne(m);
  ne[0] = -1; 
  // ne[i] = j 表示如果 i 这个位置匹配不了，下次要去 j + 1匹配，即[0,j]和[i-j,i]是一样的
  for (int i = 1, j = -1; i < m; i++) {
    while (j >= 0 && (y[j + 1] != y[i] || x[j + 1] != x[i])) j = ne[j];
    if (y[j + 1] == y[i] && x[j + 1] == x[i]) j ++;
    ne[i] = j;
  }

  // debug(n, m);;
  for (int i = 0, j = -1; i < n; i++) {
    while (j != -1 && (b[i] != y[j + 1] || ((j + 1 == m - 1 || j + 1 == 0) ? a[i] < x[j + 1] : a[i] != x[j + 1]) )) j = ne[j];
    // cout << i << " " << j << " < \n";
    if ( b[i] == y[j + 1] && ((j + 1 == 0 || j + 1 == m - 1) ? a[i] >= x[j + 1] : a[i] == x[j + 1] ) ) j++;
    if (j == m - 1) {
      ++ ans;
      // cout << i << " " << j << "\n";
      j = ne[j];
      while (j != -1 && a[i] != x[j]) {
        j = ne[j];
      }
      if (j == -1 && (a[i] >= x[0] && b[i] == y[0])) {
        ++ j;
      }
      
    }
    // cout << i << " " << j << " > \n";
  }


  cout << ans << "\n";
  


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
