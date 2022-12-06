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
  string s; cin >> s;
  string t = "atcoder";
  vector<int> a(7);
  for(int i = 0; i < 7; i ++ ) {
    a[i] = t.find(s[i]);
  }

  int ans = 0;
  for(int i = 0; i < 7; i ++ ) {
    for(int j = i + 1; j < 7; j ++ ) {
      if(a[j] < a[i]) {
        ++ ans;
      }
    }
  }
  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}