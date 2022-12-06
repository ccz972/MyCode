#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

#define int long long

constexpr int N = 2E5 + 10;

struct node {
  int op;
  ll x, y;
  char X, Y;
} q[N];
template<typename T> 
inline void Discrete (vector<T> &all) {
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
}

bool st[N];

int col[N];


int fa[N], sz[N];

int query(int x) {
  if(fa[x] != x) fa[x] = query(fa[x]);
  return fa[x];
}



void solve() {
  int n; cin >> n;
  // vector<int> col(n + 10);
  
  vector<ll> all;
  for(int i = 0; i < n; i ++ ) {
    // string op; cin >> op;
    string s; cin >> s;
    if(s[0] == 'a') {
      q[i].op = 1;
      cin >> q[i].x >> q[i].y >> q[i].X >> q[i].Y;
      all.push_back(q[i].x);
      all.push_back(q[i].y);
    } else if(s.back() == 'y') {
      q[i].op = 2;
      cin >> q[i].x;
      all.push_back(q[i].x);
    } else {
      q[i].op = 3;
    }
  }
  all.push_back(1ll);
  Discrete(all);

  auto find = [&] (ll x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };

  for(int i = 0; i < N; i ++ ) {
    fa[i] = i;
  }

  for(int i = 0; i < n; i ++ ) {
    int op = q[i].op ;
    if(op == 1) {
      auto [op, x, y, X, Y] = q[i];
      if(X == 'F') {
        sz[find(x)] = 1;
        if(x != 1ll)
        col[find(x)] = 1;
      } 
      if(Y == 'F') {
        sz[find(y)] = 1;
        if(y != 1ll)
        col[find(y)] = 1;
      }
    }
  }

  // debug(all);
  int sum = 0;
  int head = find(1ll);
  // debug(head, query(head));
  for(int i = 0; i < n; i ++ ) {
    int op = q[i].op; 
    if(q[i].op == 1) {
      auto [op, x, y, X, Y] = q[i];
      ll fx = find(x), fy = find(y);
      fx = query(fx), fy = query(fy);
      int fhead = query(head);
      if(fx != fy) {
        if(fx == fhead) {
          sum += sz[fy];
        } 
        if(fy == fhead) {
          sum += sz[fx];
        }
        fa[fx] = fy;
        sz[fy] += sz[fx];
      } 
    } else if(q[i].op == 2) {
      ll x = q[i].x;
      int now = find(x);
      int fnow = query(now);
      int fhead = query(head);
      if(fnow == fhead && col[now] == 1) {
        // debug(x, now, fnow, fhead, col[now]);
        cout << "YES\n";
      } else {
        // debug(x, now, col[now]);
        cout << "NO\n";
      }
    } else {
      cout << sum << "\n";
    }
  }




}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
