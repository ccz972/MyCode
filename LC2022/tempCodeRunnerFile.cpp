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
    vector<int> dp(1 << m, 1E7);
    dp[0] = 0;
    
    vector<vector<int> > cost(9);
    for (int i = 1; i <= 8; i ++ ) {
      cost[i].resize(1 << i);
      for (int j = 0; j < 1 << i; j ++ ) cost[i][j] = 1E7;
    }

    auto val = [] (int n, int now, int bit) {
      int l = 0, r = 0;
      for (int i = 0; i < bit; i ++ ) if (not (now >> i & 1)) ++ l;
      for (int i = n - 1; i > bit; i -- ) if (not (now >> i & 1)) ++ r;
      return l * r;
    };

    auto get = [&] (int id) {
      // cost[id][(1 << id) - 1] = 0;
      cost[id][0] = 0;
      for (int i = 0; i < 1 << id; i ++ ) {
        for (int j = 0; j < id; j ++ ) if (not (i >> j & 1)) {
          chkmin(cost[id][i ^ (1 << j)], cost[id][i] + val(id, i, j));
        }
      }
    };
    for (int i = 1; i <= 8; i ++ ) {
      get(i);
      cout << cost[i][(1 << i) - 1] << "\n";
    }
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
