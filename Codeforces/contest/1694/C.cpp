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

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for(int &x: a) cin >> x;
  ll s = 0;
  int i;
  for(i = 0; i < n; i ++ ) {
    s += a[i];
    if(s < 0) {
      cout << "NO\n";
      return ;
    } else if(s == 0) {
      i ++;
      break;
    }
  }
  for(; i < n; i ++ ) {
    s += a[i];
    if(s != 0) {
      cout << "NO\n";
      return;
    }
  }
  // s += a.back();
  if(s != 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}