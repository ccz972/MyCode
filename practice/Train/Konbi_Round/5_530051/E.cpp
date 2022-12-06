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
constexpr int N = 5001;

int dist[N][N];
int last[N][N];
bool st[N][N];

void solve() {
  int n, m, t; cin >> n >> m >> t;
  vector<vector<pair<int, int> > > son(n + 1);
  for (int i = 1; i <= m; i++ ) {
    int u, v, w; cin >> u >> v >> w; // u --, v --;
    son[u].push_back(make_pair(v, w)); //son[v].push_back(make_pair(u, w));
  }

  struct node {int c, u, dis; bool operator < (const node& T) const {return dis > T.dis ;} };

  memset(dist, 0x3f, sizeof dist);
  memset(last, -1, sizeof last);
  dist[1][1] = 0;
  last[1][1] = 0;
  priority_queue<node> q;
  q.push({1, 1, 0});
  while (!q.empty()) {
    auto [c, u, dis] = q.top(); q.pop();
    if (st[c][u]) continue;
    st[c][u] = true;
    for (auto& [v, w] : son[u]) {
      // debug(u, v, w);
      if (dis + w < dist[c + 1][v]) {
        dist[c + 1][v] = dis + w;
        last[c + 1][v] = u;
        q.push({c + 1, v, dis + w});
      }
    }
  }

  auto print = [&] (int c, int u) {
    cout << c << "\n";
    vector<int> ans;
    while (u != 0) {
      ans.push_back(u);
      u = last[c][u];
      -- c;
    }
    reverse(all(ans));
    for (int x: ans) cout << x << " ";
  };


  for (int i = 5000; i >= 1; i -- ) {
    if (dist[i][n] <= t) {
      print(i, n);     
      return ;
    }
  }

  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}