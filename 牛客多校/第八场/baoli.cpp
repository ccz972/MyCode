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
template<typename T> 
inline void Discrete (vector<T> &all) {
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
}


void solve() {
  int n, m; cin >> n >> m;
  int p, A, B, C; ll x; cin >> p >> x >> A >> B >> C;
  vector<int> a(n + 1), b(m + 1);
  for(int i = 1; i <= n; i ++ ) {
    x = (x * x * A + x * B + C) % p;
    a[i] = x;    
  }
  for(int i = 1; i <= n; i ++ ) {
    x = (x * x * A + x * B + C) % p;
    b[i] = x;    
  }

  vector<vector<int> > dp(m + 1, vector<int>(n + 1));

  for(int i = 1; i <= m; i ++ ) {
    for(int j = 1; j <= n; j ++ ) {
      if(b[i] == a[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  cout << dp[m][n] << "\n";
  
  


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}