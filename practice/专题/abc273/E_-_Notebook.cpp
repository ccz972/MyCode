#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 5E5 + 10;
constexpr int INF = 0x3f3f3f3f;
vector<array<int, 3> > son[N];
array<int, 2> a[N];
int ans[N];
bool vis[N];

void solve() {
  int n; cin >> n;  
  map<int, int> mp;
  int now = 0;
  for (int i = 1; i <= n; i ++ ) {
    string s; cin >> s;
    if (s[0] == 'A') {
      int x; cin >> x;
      // a[i] = {1, x};
      son[now].push_back({i, 1, x});
      now = i;

    } else if (s[0] == 'D') {
      // a[i] = {2, -1};
      son[now].push_back({i, 2, -1});
      now = i;
    } else if (s[0] == 'S') {
      int x; cin >> x;
      // pm[i] = i - 1;
      vis[i] = true;
      mp[x] = now;
    } else {
      int x; cin >> x;
      son[mp[x]].push_back({i, -1, -1});
      now = i;
    }
  }

  memset(ans, 0x3f, sizeof ans);
  vector<int> b;
  function<void(int)> dfs = [&] (int u) {
    // debug(u);
    for (auto [v, op, x]: son[u]) {
      int last = INF;
      if (op == 1) {
        b.emplace_back(x);
      } else if (op == 2) {
        if (!b.empty()) {
          last = b.back();
          b.pop_back();
        }
      }
      // debug(v, b);
      if (!b.empty()) {
        ans[v] = b.back();
      } else {
        ans[v] = -1;
      }

      dfs (v);

      if (op == 1) {
        b.pop_back();
      } else if (op == 2) {
        if (last != INF) {
          b.emplace_back(last);
        }
      }
    }

  };
  
  dfs (0);
  ans[0] = -1;
  for (int i = 1; i <= n; i ++ ) {
    if (ans[i] == INF) ans[i] = -1;
    
    if (vis[i]) {
      ans[i] = ans[i - 1];
    } 
    cout << ans[i] << " ";    
  }

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
