#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  ll a, b, c, d; cin >> a >> b >> c >> d;
  cout << (a + b) * (c - d) << "\n";
  cout << "Takahashi";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
