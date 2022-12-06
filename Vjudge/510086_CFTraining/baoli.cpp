#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &x: a) cin >> x;
  int now = 0;
  for (int i = 0; i < n - 1; i ++ ) {
    for (int j = i + 1; j < n; j ++ ) {
      now ^= (a[i] + a[j]);
    } 
  }
  cout << now << "\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();

  return 0;
}
