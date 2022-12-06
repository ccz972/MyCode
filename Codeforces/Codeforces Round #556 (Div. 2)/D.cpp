/***************************************************

@File    : D.cpp
@Time    : 2022/07/26 08:34:08
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

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

constexpr int N = 255;
constexpr int M = 1E5 + 10;
constexpr int INF = 1E9 + 7;
int dp[N][N][N];
int nxt[M][26];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  string t; cin >> t; t = " " + t;
  for(int j = 0; j < 26; j ++ ) {
    nxt[n + 1][j] = INF;
    for(int i = n; i > 0; i -- ) {
      if(t[i] - 'a' == j) {
        nxt[i][j] = i;
      } else {
        nxt[i][j] = nxt[i + 1][j];
      }
      // debug(i, j, nxt[i][j]);
    }
  }

  

  vector<string> s(3, "#");
  
  auto update = [&] (int x) {
    for(int i = (x == 0 ? s[0].size() - 1 : 0); i < s[0].size(); i ++ ) {
      for(int j = (x == 1 ? s[1].size() - 1 : 0); j < s[1].size(); j ++ ) {
        for(int k = (x == 2 ? s[2].size() - 1 : 0); k < s[2].size(); k ++ ) {
          int &ret = dp[i][j][k];
          ret = INF;
          if(i && dp[i - 1][j][k] != INF) {
            chkmin(ret, nxt[dp[i - 1][j][k] + 1][s[0][i] - 'a']);
            // debug(ret, i, j, k , nxt[dp[i - 1][j][k] + 1][s[0][i] - 'a']);
          }
          if(j && dp[i][j - 1][k] != INF) {
            chkmin(ret, nxt[dp[i][j - 1][k] + 1][s[1][j] - 'a']);
            // debug(ret, i, j, k , nxt[dp[i][j - 1][k] + 1][s[1][j] - 'a']);
          }
          if(k && dp[i][j][k - 1] != INF) {
            chkmin(ret, nxt[dp[i][j][k - 1] + 1][s[2][k] - 'a']);
            // debug(ret, i, j, k , nxt[dp[i][j][k - 1] + 1][s[2][k] - 'a']);
          }
        }
      }
    }
  };

  while(q -- ) {
    char op, c; int id;
    cin >> op >> id;
    -- id;
    if(op == '+') {
      cin >> c;
      s[id].push_back(c);
      update(id);
    } else {
      s[id].pop_back();
    }

    if(dp[s[0].size() - 1][s[1].size() - 1][s[2].size() - 1] != INF) {
      // cout << dp[s[0].size()][s[1].size()][s[2].size()] << "\n";
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}