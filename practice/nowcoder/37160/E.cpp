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
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(begin(a), end(a));
  int now = 0;
  for(int i = 0; i < n; i ++ ) {
    if(a[i] > now + 1) {
      cout << now + 1 << "\n";
      return 0;
    } else {
      now += a[i];
    }
  }
  cout << now + 1 << "\n";
  return 0;
}