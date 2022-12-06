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
  int n; cin >> n;
  int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  string s;
  while (n >= 2) {
    s += '1';
    n -= 2;
  }
  if (n == 1 && !s.empty()) {
    s.pop_back();
    s.push_back('7');
    n = 0;
  }
  reverse(s.begin(), s.end());
  cout << s << "\n";  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}