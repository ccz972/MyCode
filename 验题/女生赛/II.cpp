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

constexpr int N = 5E5 + 10;
constexpr int M = 5010;

int vis[M];
int idx, dp[M][2];

struct Trie {
  int c[N][26], tot;
  bool v[N];
  void init() {
    while (tot) {
      v[tot] = 0;
      memset(c[tot], 0, sizeof c[tot]);
      -- tot;
    }
    memset(c[0], 0, sizeof c[0]);
    v[0] = 0;
  }
  void insert(string s) {
    int now = 0;
    for (int i = 0; i < SZ(s); i ++ ) {
      int to = s[i] - 'a';
      if (!c[now][to]) c[now][to] = ++ tot;
      now = c[now][to];
    }
    v[now] = 1;
  }

  void query(string s) {
    int now = 0;
    for (int i = 0; i < SZ(s); i ++ ) {
      int to = s[i] - 'a';
      if (!c[now][to]) return ;
      now = c[now][to];
      if (v[now]) vis[idx ++ ] = i + 1;
    }
  }
  
} A, B;

void solve() {
  A.init(); B.init();
  int n; cin >> n; // debug(n);
  for (int i = 0; i < n; i ++ ) {
    string s; cin >> s; reverse(all(s));
    // cout << s << "\n";
    A.insert(s);
  }
  cin >> n;
  // debug(n);
  for (int i = 0; i < n; i ++ ) {
    string s; cin >> s; reverse(all(s));
    // cout << s << "\n";
    B.insert(s);
  }

  string s; cin >> s;
  memset(dp, 0x3f, sizeof dp);
  n = SZ(s);
  // cout << min(dp[n][0], dp[n][1]) << "\n";
  dp[0][0] = dp[0][1] = 0;

  for (int i = 0; i < n; i ++ ) {
    string t; 
    for (int j = i; j >= 0; j -- ) t += s[j];
    idx = 0;
    A.query(t);
    for (int j = 0; j < idx; j ++ ) {
      int now = vis[j];
      chkmin(dp[i + 1][0], dp[i - now + 1][1] + 1);
    }
    
    idx = 0;
    B.query(t);
    for (int j = 0; j < idx; j ++ ) {
      int now = vis[j];
      chkmin(dp[i + 1][1], dp[i - now + 1][0] + 1);
    }
    // cout << min(dp[n][0], dp[n][1]) << "\n";
  }
  // n = SZ(s);
  int ans = min(dp[n][0], dp[n][1]);
  if (ans > n) ans = -1;
  cout << ans  << "\n";


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}