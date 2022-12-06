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
  vector<string> s(10);
  for (int i = 0; i < 10; i ++ ) {
    cin >> s[i];
  }
  array<int, 2> st, ed;
  for (int i = 0; i < 10; i ++ ) {
    for (int j = 0; j < 10; j ++ ) if (s[i][j] == '#') {
      st = {i + 1, j + 1};
      break;
    }
  }
  for (int i = 9; i >= 0; i -- ) {
    for (int j = 9; j >= 0; j -- ) if (s[i][j] == '#') {
      ed = {i + 1, j + 1};
      break;
    }
  }

  cout << min(st[0], ed[0]) << " " << max(st[0], ed[0]) << "\n";
  cout << min(st[1], ed[1]) << " " << max(st[1], ed[1]) << "\n";

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
