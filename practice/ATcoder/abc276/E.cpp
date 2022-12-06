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
// constexpr int N = 2E5 + 10;



void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  PII s;
  Rep(i, 0, n) Rep(j, 0, m) if (a[i][j] == 'S') {
    s = {i, j}; break;
  }
  vector<int> dx{0, 0, 1, -1}, dy = {1, -1, 0, 0};
  vector<vector<int> > dist(n, vector<int>(m, INF));
  dist[s.first][s.second] = 1;
  function<void(int, int)> dfs = [&] (int x, int y) {
    Rep(i, 0, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (a[nx][ny] == '#') continue;
      if (a[nx][ny] == 'S') {
        if (dist[x][y] + 2 >= 5) { 
          cout << "Yes\n"; exit(0);
        }
      } else if (dist[nx][ny] == INF) {
        dist[nx][ny] = dist[x][y] + 1;
        dfs(nx, ny);
      }
    }    
  };
  dfs(s.first, s.second);
  cout << "No\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}