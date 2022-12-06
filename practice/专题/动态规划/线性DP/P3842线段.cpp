#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)
#define YES cout << "YES" << "\n"; return  
#define NO  cout << "NO" << "\n";  return  

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2e4 + 10;

int n;
// array<int, 2> seg[N];
int l[N], r[N];
int f[N][2];

void solve() {
  cin >> n;
  rep(i, 1, n) {
    cin >> l[i] >> r[i];
  }
  f[1][0] = r[1] - 1 + r[1] - l[1];
  f[1][1] = r[1] - 1;

  rep(i, 2, n) {
    f[i][0] = min(f[i - 1][0] + abs(r[i] - l[i - 1]) + r[i] - l[i] + 1, f[i - 1][1] + abs(r[i] - r[i - 1]) + r[i] - l[i] + 1);
    f[i][1] = min(f[i - 1][0] + abs(l[i] - l[i - 1]) + r[i] - l[i] + 1, f[i - 1][1] + abs(l[i] - r[i - 1]) + r[i] - l[i] + 1);
    
  }
  cout << min(f[n][0] + n - l[n], f[n][1] + n - r[n]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}