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
  string a, b; cin >> a >> b;
  if(a == b) {
    cout << "YES\n";
    return ;
  }
  
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end()); 

  if(b.size() == 1) {
    if(a.find(b[0]) != -1) cout << "YES\n";
    else cout << "NO\n";
    return ;
  }

  if(a.substr(0, b.size()) == b) {
    cout << "YES\n";
    return ;
  }

  if(a.substr(0, b.size() - 1) != b.substr(0, b.size() - 1)) {
    cout << "NO\n";
    return ;
  }
  int idx = 0;
  while(a[idx] == b[idx]) {
    ++ idx;
  }
  if(a[idx] == '0') {
    bool flag = false;
    while(idx < n && !flag) {
      if(a[idx] == '1') {
        flag = true;
      }
      idx ++;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
  } else {
    bool flag = false;
    while(idx < n) {
      if(a[idx] == '0' && !flag) {
        flag = true;
      }
      idx ++;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}