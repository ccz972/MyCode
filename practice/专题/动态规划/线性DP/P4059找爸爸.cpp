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


constexpr ll inf = 1e18;

map<pair<char, char>, int> mp;

void solve() {
  string s1, s2; cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  s1 = " " + s1;
  s2 = " " + s2;
  vector<char> all{'A', 'T', 'G', 'C'};
  for(int i = 0; i < 4; i ++ ) {
    for(int j = 0; j < 4; j ++ ) {
      int x; cin >> x;
      mp[{all[i], all[j]}] = x;
    }
  }
  // cout << mp[{'G', 'C'}] << "\n";
  ll x, y; cin >> x >> y;
  vector<vector<array<ll, 3> > > f(n + 1, vector<array<ll, 3> >(m + 1, {-inf, -inf, -inf}));

  for(int i = 1; i <= n || i <= m; ++ i ) {
    if(i <= m) {
      f[0][i][1] = -x - y * (i - 1);
    } 
    if(i <= n) {
      f[i][0][2] = -x - y * (i - 1);
    }
  } 

  f[0][0][0] = 0;
  //f[i][j][0] 表示s1匹配了i个， s2匹配了j个，并且当前状态为两个字符
  //f[i][j][1] 表示s1匹配了i个， s2匹配了j个，并且当前状态为s1是空格，s2是字符
  //f[i][j][2] 表示s1匹配了i个， s2匹配了j个，并且当前状态为s1是字符，s2是空格
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      //
      //
      f[i][j][0] = max({f[i - 1][j - 1][0], f[i - 1][j - 1][1], f[i - 1][j - 1][2]}) + mp[{s1[i], s2[j]}];

      f[i][j][1] = max({f[i][j - 1][0] - x, f[i][j - 1][1] - y, f[i][j - 1][2] - x});

      f[i][j][2] = max({f[i - 1][j][0] - x, f[i - 1][j][1] - x, f[i - 1][j][2] - y}); 
      // f[i][j][1] = max({f[i - 1][j][0], f[i - 1][j][2]});
      // f[i][j][2] = max({f[i][j - 1][0], f[i][j - 1][1]});
      // printf("%d %d -> %lld %lld %lld\n", i, j, f[i][j][0], f[i][j][1], f[i][j][2]);
      // printf("f[%d][%d][%d] = %lld\n", i, j, ) 
    }
  }
  // cout << f[1][1][1] << "\n";
  cout << max({f[n][m][0], f[n][m][1], f[n][m][2]}) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}