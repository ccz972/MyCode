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

// dp[10][]

void solve() {
  int n; cin >> n;  
  vector<array<int, 3> > A(n);
  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < 3; j ++ ) {
      cin >> A[i][j];
    }
  }

  ll ans = 0;
  //dp[i][j] {}

  vector<vector<pair<int, ll> > > dp(6, vector<pair<int, ll> >(6, {-1, -1E18}));

  dp[0][0] = {0, 0};

  


  // vector<ll> dp(5, -1E18);
  // dp[0] = 0;
  // vector<pair<int, ll> > dp(5, {-1, -1E18});
  //上次的时间，价值()



  // dp[0] = {0, 0};
  
  for (auto [t, x, a]: A) {
    pair<int, ll> ret;
    ret.first = t;
    ret.second = -1;
    // debug(x);
    for (int i = 0; i < 5; i ++ ) {
      for (int j = 0; j < 5; j ++ ) if (dp[i][j].first != -1) {
        //
        if (t - dp[i][j].first >= abs(x - i)) {
          // debug(t, x, a, i, j, dp[i][j].first, abs(x - i));
          chkmax(ret.second, dp[i][j].second + a);
        }
      }
    }
    
    if (ret.second == -1) continue;
    
    for (int j = 4; j >= 1; j -- ) {
      // debug(dp.size(), x); return ;
      // assert(x < dp.size());
      // assert(j < dp[x].size());
      // assert(j - 1 >= 0);
      dp[x][j] = dp[x][j - 1];
      
    }
    // debug("FIUCK");return;
    dp[x][0] = ret;
    
  }
  
  for (int i = 0; i < 5; i ++ ) {
    for (auto [k, v]: dp[i]) {
      chkmax(ans, v);
    }
  }
  

  cout << ans;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}