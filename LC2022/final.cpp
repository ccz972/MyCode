#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
clock_t start = clock();
#else
#define debug(...) 42
#endif

class Solution {
 public:
  template <typename T>
  void chkmax(T& x, T y) {
    x = max(x, y);
  }
  template <typename T>
  void chkmin(T& x, T y) {
    x = min(x, y);
  }

  int Leetcode(vector<string>& a) {
    string s = "helloleetcode";
    sort(s.begin(), s.end());
    int n = a.size(), m = s.size();
    vector<long long> dp(1 << m, 1E18);
    dp[0] = 0;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (string& t : a) {
      vector<bool> vis(t.size());
      vector<int> need(26), nneed(26);
      for (char c: s) nneed[c - 'a'] ++;
      int N = t.size();
      function<void(int, int)> dfs = [&](int now, int ti) {
        if (ti == N) {
          return;
        }
        vector<int> val(t.size());
        val[0] = 0;
        for (int i = 1; i < t.size(); i++) val[i] = val[i - 1] + !vis[i - 1];
        int cnt = !vis[(int)t.size() - 1];
        val[(int)t.size() - 1] = 0;
        for (int i = (int)t.size() - 2; i >= 0; i--)  if (vis[i]) {
          val[i] = 0;
        } else {
          val[i] *= cnt;
          ++cnt;
        }
        for (int i = 0; i < N; i++)
          if (need[t[i] - 'a'] && !vis[i]) {
            need[t[i] - 'a'] --;
            vis[i] = true;
            for (int j = 0; j < m; j++)
              if ((not (now >> j & 1)) && s[j] == t[i]) {
                if (dp[now ^ (1 << j)] > dp[now] + val[i]) {
                  // chkmin(dp[now ^ (1 << j)], dp[now] + val[i]);
                  dp[now ^ (1 << j)] = dp[now] + val[i];
                  dfs(now ^ (1 << j), ti + 1);
                }
                break;
              }
            vis[i] = false;
            need[t[i] - 'a']++;
          }
      };
      for (int i = (1 << m) - 1; i >= 0; i -- ) if (dp[i] < 1E9) {
        for (char c : s) need[c - 'a'] = nneed[c - 'a'];
        for (int j = 0; j < m; j++)
          if (i >> j & 1) 
            need[s[j] - 'a']--;
          
        dfs(i, 0);
      }
    }
    if (dp[(1 << m) - 1] < 1E9) return dp[(1 << m) - 1];
    return -1;
  }
};

void solve() {
  Solution solu;
  vector<string> s{"hold","engineer","cost","level"};
  vector<string> t{"hello","leetcode"};
  vector<string> p{"lkhqjztn","cpoipalb","hrke","fveuttt","conrzlm","tdrohwgm","odzetred","jekj","lh","kelzwh"};
  // 7
  auto res = solu.Leetcode(p);
  cout << res << "\n";
}
int main() {
  // freopen("1.txt", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC *
  // 1000 << "ms" << endl;
#endif
  return 0;
}
