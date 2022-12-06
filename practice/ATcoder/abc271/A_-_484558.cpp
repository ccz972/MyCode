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
  string s;
  while (n) {
    auto t = n % 16;
    if (t <= 9) s += '0' + t;
    else s += 'A' + (t - 10);
    n /= 16;
  }
  while ((int)s.size() <= 1) s.push_back('0');
  reverse(s.begin(), s.end());
  cout << s ;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}