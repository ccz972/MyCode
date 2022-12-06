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
struct node {
  int ver, distance;
  bool operator < (const node &T) const {
    return T.distance < distance;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n); for(auto& s: a) cin >> s;

  vector<vector<int> > g(n + 2, vector<int>(n + 2, 1E9));
  string s, t; cin >> s >> t; //n, n + 1
  a.push_back(s); a.push_back(t);
  for(int i = 0; i < n + 2; i ++ ) {
    for(int j = i + 1; j < n + 2; j ++ ) {
      int cnt = 0;
      for(int k = 0; k < m && cnt <= 1; k ++ ) if(a[i][k] != a[j][k]) {
        ++ cnt;
      }
      if(cnt <= 1) {
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  // debug(g);
  priority_queue<node> q;
  vector<bool> st(n + 2);
  vector<int> dist(n + 2, 1E9);
  vector<int> last(n + 2, -1);

  dist[n + 1] = 0;
  
  for(int i = 0; i < n + 2; i ++ ) {
    int t = -1;
    for(int j = 0; j < n + 2; j ++ ) if(!st[j]) {
      if(t == -1 || dist[t] > dist[j]) {
        t = j;
      }
    }

    st[t] = true;

    for(int j = 0; j < n + 2; j ++ ) if(dist[j] > dist[t] + g[t][j]) {
      dist[j] = dist[t] + g[t][j];
      last[j] = t;
    }
    // debug(dist);
  }

  // debug(dist);

  if(dist[n] > n + 10) {
    cout << "-1\n";
    return;
  }

  cout << dist[n] - 1 << "\n";
  int now = n;

  while(true) {
    cout << a[now] << "\n";
    if(now == n + 1) break;
    now = last[now];
  }


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}