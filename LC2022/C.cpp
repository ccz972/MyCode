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

  int Leetcode(vector<string>& words) {
    // int n = words.size();
    string s = "helloleetcode"; sort(s.begin(), s.end());
    int n = s.size();
    vector<int> use(310); for (char c: s) use[c] ++;
    vector<int> dp(1 << n, 1E8); dp[0] = 0;
    vector<vector<int> > cost(9);
    for (int i = 0; i < 9; i ++ ) cost[i].resize(1 << i);
    vector<vector<int> > f(26);
    for (int i = 0; i < n; i ++ ) f[s[i] - 'a'].emplace_back(i);
    auto get = [] (int n, int bit) -> int {
      //长为i，状态为j
      int cost = 0;
      for (int i = 0; i < n && i <= n - i - 1; i ++ ) if((bit >> i & 1) || (bit >> (n - i - 1) & 1)) {
        int now = (bit >> i & 1) + (bit >> (n - i - 1) & 1);
        if (now == 1 || (i == n - i - 1)) {
          if (bit >> i & 1) {
            int l = 0, r = 0;
            for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
              ++ l;
            }
            for (int j = n - 1; j > n - 1 - i; j -- ) if (!(bit >> j & 1)) {
              ++ r;
            }

            for (int j = i + 1; j <= n - 1 - i; j ++ ) {
              ++ r;
            }
            
            cost += l * r;
          } else {
            int l = 0, r = 0;
            for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
              ++ l;
            }

            for (int j = i; j < n - 1 - i; j ++ ) {
              ++ l;
            }

            for (int j = n - 1; j > n - i - 1; j -- ) if (!(bit >> j & 1)) {
              ++ r;
            }
            // cout << l << " " << r << "\n";
            cost += l * r;
          }
        } else {
          int cnt1 = 0, cnt2 = 0;
          for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
            ++ cnt1;
          }
          for (int j = n - 1; j > n - i - 1; j -- ) if (!(bit >> j & 1)) {
            ++ cnt2;
          }

          if (cnt1 <= cnt2) {
            //先删左边再删右边
            int l = 0, r = 0;
            for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
              ++ l;
            }
            for (int j = n - 1; j > n - 1 - i; j -- ) if (!(bit >> j & 1)) {
              ++ r;
            }

            for (int j = i + 1; j <= n - 1 - i; j ++ ) {
              ++ r;
            }
            cost += l * r;

            l = 0, r = 0;

            for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
              ++ l;
            }

            for (int j = i + 1; j < n - 1 - i; j ++ ) {
              ++ l;
            }

            for (int j = n - 1; j > n - i - 1; j -- ) if (!(bit >> j & 1)) {
              ++ r;
            }

            cost += l * r;

          } else {
            int l = 0, r = 0;
            for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
              ++ l;
            }

            for (int j = i; j < n - 1 - i; j ++ ) {
              ++ l;
            }

            for (int j = n - 1; j > n - i - 1; j -- ) if (!(bit >> j & 1)) {
              ++ r;
            }
            cost += l * r;

            l = 0, r = 0;

            for (int j = 0; j < i; j ++ ) if (! (bit >> j & 1)) {
              ++ l;
            }
            for (int j = n - 1; j > n - 1 - i; j -- ) if (!(bit >> j & 1)) {
              ++ r;
            }

            for (int j = i + 1; j < n - 1 - i; j ++ ) {
              ++ r;
            }
            cost += l * r;
          }
        }
        // cout << cost << "\n";
      }
      return cost;
    };
    // cout << get(4, 10) << endl;
    for (int i = 1; i <= 8; i ++ ) {
      for (int j = 0; j < 1 << i; j ++ ) {
        cost[i][j] = get(i, j);
        // cout << i << " " << j << " " << cost[i][j] << endl;
      }
    }
    // cout << "FUCK" << endl;

    for (string&t : words) {
      int m = t.size();
      auto P = dp;
      for (int i = 1; i < 1 << m; i ++ ) {
        bool flag = true;
        for (int j = 0; j < m && flag; j ++ ) if (i >> j & 1) {
          if (!use[t[j]]) flag = false;
        }

        if (!flag) continue;

        auto check = [&] (int x, int y) -> int {
          int p = y;
          
          for (int j = 0; j < m; j ++ ) if (x >> j & 1) {
            bool flag = false;
            for (int k: f[t[j] - 'a']) if (!(p & (1 << k))) {
              flag = true;
              p |= 1 << k; 
              break;
            }
            if (!flag) return -1;
          } 
          assert(p < (1 << n));
          // cout << "x = " << x << " y = " << y << "dp[fuck] = " << dp[p] << " " << " dp[j] + cost[m][i]" << " " << dp[y] + cost[m][x] << endl;
          return p;
        };
        // cout << "fuck" << endl;
        for (int j = (1 << n) - 1; j >= 0; j -- ) if (P[j] < 1E8) {
          
          auto fuck = check(i, j);
          
          // cout << j << " " << fuck << endl;

          if (fuck == -1) continue;
          // cout << t << endl << s << endl;
          // for (int k = 0; k < m; k ++ ) if (i >> k & 1) {
          //   cout << t[k];
          // }
          // cout << endl;
          // for (int k = 0; k < n; k ++ ) if (fuck >> k & 1) {
          //   cout << s[k];
          // }
          // cout << endl << endl;

          // assert(fuck < (1 << n));
          // assert(cost[m][i] >= 0);
          // assert(i < (1 << m));
          // debug(dp[fuck], dp[j] + cost[m][i]);
          // cout << dp[fuck] << " " << dp[j] + cost[m][i] << endl;
          chkmin(dp[fuck], P[j] + cost[m][i]);
          // if (cost[m - 1][i] < 0) {
          //   cout << m << " " << i << " " << cost[m - 1][i] << endl;
          // }
        }
      }
    }
    // cout << "fuck\n" << endl;
    // cout << dp.back() << endl;
    // cout << dp[1218] << endl;
    // cout << dp[1222] << endl;
    // auto idx = max_element(dp.begin(), dp.end());
    // cout << (idx - dp.begin()) << endl << *idx << endl;

    if (dp.back() < 1E9) return dp.back();
    return -1;
  }
};

void solve() {
  Solution solu;
  vector<string> s{"hold", "engineer", "cost", "level"};
  vector<string> t{"hello", "leetcode"};
  vector<string> p{"lkhqjztn","cpoipalb","hrke","fveuttt","conrzlm","tdrohwgm","odzetred","jekj","lh","kelzwh"};
  vector<string> P{"puoube","ooyroohy","digj","hbsi","iztdk","dzpgkeu","fhvtew","lltea","onlequ","svgvg","qldnydmp","koldxhit","yh","ogsnllt","hc","cg","sioi","lczvch","ug"};
  auto res = solu.Leetcode(P);
  cout << res << endl;
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
