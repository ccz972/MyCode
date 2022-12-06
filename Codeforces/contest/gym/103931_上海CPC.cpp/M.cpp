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
#define dec(i, a, b) for (int i(a); i >= b; -- i ) 

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
// constexpr int N = 2E5 + 10;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int> > a(m + 1, vector<int>(n + 1));  
  vector<vector<int> > pos(m + 1, vector<int>(n + 1));  
  vector<bool> vis(n + 1);
  vector<int> R(m + 1);
  vector<int> ans(n + 1);
  rep(i, 1, m) {
    rep(j, 1, n) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  }

  rep(j, 1, n) {
    rep(i, 1, m) if (!vis[a[i][j]]) {
      int now = a[i][j];
      chkmax(ans[now], n - j);
      rep(k, 1, m) {
        int idx = pos[k][now];
        dec(p, idx - 1, R[k] + 1) {
          int q = a[k][p];
          // if (q == 4) debug(q, ans[q], now, ans[now]);
          chkmax(ans[q], ans[now]);
           
        }
        chkmax(R[k], idx);
      }
      vis[now] = true;
    }
  }

  rep(i, 1, n) {
    cout << ans[i] << " \n"[i == n];
  }



  // vector<vector<int> > a(n + 1, vector<int>(m + 1));  
  // rep(i, 1, m) {
  //   rep(j, 1, n) {
  //     cin >> a[j][i];
  //   }
  // }

  // set<int> s[n + 1];

  // rep(i, 1, n) {

  // }


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}