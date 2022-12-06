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
constexpr int N = 210;
vector<vector<PII> > f;
int n; 
int a[N][N];
bool vis[N][N];
vector<PII> now;

void dfs(int x, int y) {
  if (x == n - 1 && y == n - 1) {
    now.push_back({x, y});
    f.push_back(now);
    now.pop_back();
    return ;
  }
  now.push_back({x, y});
  vis[x][y] = true;
  if (!vis[(x + 1) % n][y]) {
    dfs((x + 1) % n, y);
  }

  if (!vis[x][(y + 1) % n]) {
    dfs(x, (y + 1) % n);
  }
  vis[x][y] = false;
  now.pop_back();
}

void solve() {
  cin >> n;
  // for (int i = 0; i < n; i ++ ) {
  //   for (int j = 0; j < n; j ++ ) {
  //     cin >> a[i][j];
  //   }
  // }  
  vis[0][0] = true;
  dfs(0, 0);
  sort(all(f), [&](auto &x, auto &y) {
    if (SZ(x) != SZ(y)) {
      return SZ(x) > SZ(y);
    }
    return x > y;
  });
  cout << SZ(f.front()) << "\n";
  for (auto x: f) {
    Rep(i, 0, n) Rep(j, 0, n) vis[i][j] = false;
    for (auto [p, q]: x) vis[p][q] = true;
    int cnt = 0;
    Rep(i, 0, n) cnt += vis[i][i];
    if (cnt == n) {
      debug(x);
      Rep(i, 0, n) Rep(j, 0, n) if (!vis[i][j]) {
        debug(i, j);
      }
    } 
      
    
    // debug("-----------------");
  }
  // debug(f);
  // cout << SZ(f);

}

void solve2() {
  int n; cin >> n;
  vector<vector<ll> > a(n, vector<ll>(n));
  ll sum = 0;
  ll mi = 1E18;
  Rep(i, 0, n) {
    Rep(j, 0, n) {
      cin >> a[i][j];
      sum += a[i][j];
    }
    chkmin(mi, a[i][n - i - 1]);
  }
  cout << sum - mi << "\n";
}


int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  // freopen("3.txt", "w", stdout);
  int T = 1; //cin >> T;
  while (T --) solve2();
  return 0;
}