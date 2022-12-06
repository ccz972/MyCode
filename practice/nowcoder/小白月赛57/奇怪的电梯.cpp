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
  ll n, k, a, b; cin >> n >> k >> a >> b;
  if (abs(a - b) > k || a == b) {
    cout << "YES\n";
  } else {
    if (abs(a - 1) > k || abs(a - n) > k) {
      if (abs(b - 1) > k || abs(b - n) > k) {
        cout << "YES\n";
        return ;
      }
    }
    cout << "NO\n";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}