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

bool vis[4][4];

bool chk (int x, int y) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < 3; i ++ ) {
    cnt1 += vis[i][y];
    cnt2 += vis[x][i];
  }
  if (cnt1 == 3 || cnt2 == 3) return true;
  if (x == y) {
    int cnt = 0;
    for (int i = 0; i < 3; i ++ ) cnt += vis[i][i];
    return cnt == 3;
  } else if (x + y == 2) {
    int cnt = 0;
    for (int i = 0; i < 3; i ++ ) cnt += vis[i][2 - i];
    return cnt == 3;
  } else {
    return false;
  }
  
}

bool dfs(int x, int y) {
  if (chk(x, y)) return 1;
  int win = 0, lose = 0;
  int all = 0;
  for (int i = 0; i < 3; i ++ ) {
    for (int j = 0; j < 3; j ++ ) if (!vis[i][j]) {
      vis[i][j] = true;
      bool state = dfs(i, j);
      vis[i][j] = false;
      if (state) ++ win;
      else ++ lose;
      ++ all;

    }
  }
  if (win) return false;
  if (lose == all) return true;
  return false;
}

void solve() {
  int x, y; cin >> x >> y;
  -- x, -- y;
  vis[x][y] = true;
  bool state = dfs(x, y);
  if (state) cout << "YES\n";
  else cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}