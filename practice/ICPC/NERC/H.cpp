#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;

namespace Nanfeng1 {
  constexpr int N = 2010;
  int n, m;   
  int p[N], idx[N], s[N], dp[N];
  bool vis[N];
  void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> p[i], idx[i] = i, s[p[i]] ++;
    rep(i, 1, n) {
      s[i] += s[i - 1];
      if (s[i] == i) {
        vis[i] = true;
      }
    }
    sort(idx + 1, idx + n + 1, [&](int x, int y) {
      return p[x] < p[y];
    });
    for (int i = 1; i <= n; i ++ ) {
      int j = i;
      while (j + 1 <= n && s[idx[j + 1]] != idx[j + 1]) {
        ++ j;
      }
      int k = j;
      while (k + 1 <= n && idx[k + 1] == idx[j]) {
        ++ k;
      }
      for (int l = i; l <= k; l ++ ) dp[idx[l]] = i;
      debug(i, k, idx[i], idx[k]);
      i = k;
    } 
    rep(i, 1, n) cout << dp[i] << " \n"[i == n];
  }
}


namespace Nanfeng {
  void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int> > p(n);
    Rep(i, 0, n) {
      p[i].second = i + 1;
      cin >> p[i].first;
    }
    vector<int> dp (n + 1);
    sort(all(p));

    for (int i = 0; i < n; i ++ ) {
      if (i + 1 == p[i].first) {
        dp[p[i].second] = i + 1;
      } else {
        int j = i;
        while (j + 1 < n && j + 2 != p[j + 1].first) {
          ++ j;
        }
        if (j + 1 < n) ++ j;
        for (int k = i; k <= j; k ++ ) {
          dp[p[k].second] = i + 1;
        }
        i = j;
      }
    }
    // for (int i = 1; i <= n; i ++ ) {
    //   cout << dp[i] << " \n"[i == n];
    // }
    vector<int> d(n + 1); 
    vector<vector<int> > son(n + 1);
    auto ndp = dp;
    rep(i, 1, m) {
      int x, y; cin >> x >> y;
      if (dp[x] != dp[y]) continue;
      son[x].push_back(y);
      d[y] ++;
      ndp[y] ++;
    }

    vector<bool> vis(n + 1);

    queue<int> q;
    rep(i, 1, n) if (!d[i]) {
      q.push(i);
      vis[i] = true;
    }
    while (q.size()) {
      auto u = q.front(); q.pop();
      for (auto &v: son[u]) {
        chkmax(ndp[v], dp[u] + 1);
        if (-- d[v] == 0) {
          if (!vis[v]) {
            q.push(v);
            vis[v] = true; 
          }
        }
      }
    }

    for (int i = 1; i <= n; i ++ ) cout << min(n, ndp[i]) << " ";
  
  }
}



int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) Nanfeng::solve();
  return 0;
}