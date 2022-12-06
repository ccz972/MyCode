//url: https://www.luogu.com.cn/problem/CF1168B

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
constexpr int N = 3E5 + 10;

struct Trie {
  int c[N][2], tot, v[N];
  void init() {
    while (tot) {
      v[tot] = 0;
      // memset(c[tot], 0, sizeof(c[tot]));
      c[tot][0] = c[tot][1] = 0;
      --tot;
    }
    // memset(c[0], 0, sizeof(c[0]));
    c[0][0] = c[0][1] = 0;
    v[0] = 0;
  }
  void insert(string &s, int len) {
    int now = 0;
    for (int i = 0; i < len; ++i) {
      int to = s[i] - '0';
      if (!c[now][to])c[now][to] = ++tot;
      now = c[now][to];
    }
    v[now] = 1;
  }

  bool query(string &s, int len) {
    int now = 0;
    for (int i = 0; i < len; i ++ ) {
      int to = s[i] - '0';
      if (!c[now][to])return 0;
      now = c[now][to];
    }
    return v[now];
  }
} A;


bool check(string &s) {
  int n = SZ(s);
  for (int x = 0; x < n; x ++ ) {
    for (int k = 1; x + 2 * k < n; k ++ ) {
      if (s[x] == s[x + k] and s[x] == s[x + 2 * k]) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  A.init();
  string s; cin >> s;
  int n = SZ(s);
  ll ans = 0;
  for (int i = 1; i <= 9; i ++ ) {
    for (int j = 0; j < 1 << i; j ++ ) {
      string s; 
      for (int k = 0; k < i; k ++ ) if (j >> k & 1) {
        s += '1';
      } else {
        s += '0';
      }
      if (check(s)) {
        A.insert(s, SZ(s));
      }
    }
  }

  for (int i = 0; i < n; i ++ ) {
    int j = i + 9;
    if (j < n) ans += n - j;
    string t;
    chkmin(j, n);
    for (int k = i; k < j; k ++ ) {
      t += s[k];
      if (A.query(t, SZ(t))) ++ ans;
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}