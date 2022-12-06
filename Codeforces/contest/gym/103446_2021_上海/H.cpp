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
constexpr int N = 1E5 + 10;

struct node {
  int u, v, w; 
  bool operator < (const node &T) const {
    return w < T.w;
  }
} e[N];

int n, m, q; 
int a[N], p[N], ans[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]); 
  return p[x];
}

// multiset<pair<int, int> > s[N];
priority_queue<PII, vector<PII>, greater<PII>> s[N];

void solve() {
  cin >> n >> m >> q;
  rep(i, 1, n) p[i] = i;
  rep(i, 1, n) cin >> a[i];
  Rep(i, 0, m) cin >> e[i].u >> e[i].v >> e[i].w; sort(e, e + m);
  Rep(i, 0, q) {int x, k; cin >> x >> k; s[x].push(make_pair(k, i)); }
  Rep(i, 0, m) {
    auto [u, v, w] = e[i];
    u = find(u), v = find(v);
    if (u == v) continue;
    //从 x 出发的集合无法跨过 w
    while (!s[u].empty() && (s[u].top().first < w - a[u])) {
      auto [x, id] = s[u].top(); 
      ans[id] = a[u] + x;
      // s[u].erase(s[u].top());
      s[u].pop();
    }

    swap(u, v);

    while (!s[u].empty() && (s[u].top().first < w - a[u])) {
      auto [x, id] = s[u].top(); 
      ans[id] = a[u] + x;
      // s[u].erase(s[u].top());
      s[u].pop();
    }


    swap(u, v);

    if (s[u].size() > s[v].size()) {
      swap(u, v);
    }

    while (!s[u].empty()) {
      auto t = s[u].top(); s[u].pop();
      s[v].push(t);
      // s[v].insert(s[u].extract(s[u].begin()));
    }

    p[u] = v;
    a[v] += a[u];

  }

  rep(i, 1, n) {
    int fa = find(i);
    while (!s[fa].empty()) {
      auto [x, id] = s[fa].top(); s[fa].pop();
      ans[id] = a[fa] + x;
    }
    // for (auto [x, id]: s[fa]) {
    //   ans[id] = a[fa] + x;
    // }
    // s[fa].clear();
  }
  Rep(i, 0, q) cout << ans[i] << "\n";
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}