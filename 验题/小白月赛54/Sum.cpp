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

constexpr int p = 1E7 + 7;

void solve() {
  int n; cin >> n;
  priority_queue<ll> q;
  for(int i = 0; i < n; i ++ ) {
    int x; cin >> x; q.push(x);
  }
  ll ans = 0;
  while(q.size() > 1) {
    auto t1 = q.top(); q.pop();
    auto t2 = q.top(); q.pop();
    if(t1 + t2 <= 0) break;
    ans += t1 + t2; ans %= p;
    q.push(t1 + t2);
  }
  cout << ans << "\n";

  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}