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

constexpr int N = 2010;
constexpr int M = N * N;


struct node {
  int u, v;
  long long dis;
  bool operator <(const node &T ) const {
    return dis < T.dis;
  }
} p[M] ;

struct point {
  ll x, y;
} a[N] ;

long long distan(point p1, point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int f[N], g[N];

void solve() {
  int n; cin >> n;
  a[0].x = a[0].y = 0;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i].x >> a[i].y;
  } 
  int m = 0; 
  for(int i = 0; i <= n; i ++ ) {
    for(int j = i + 1; j <= n; j ++ ) {
      p[m ++ ] = {i, j, distan(a[i], a[j])};
    }
  }
  
  sort(p, p + m);

  for(int i = 1; i <= n; i ++ ) {
    f[i] = g[i] = 1;
  }

  int id = 3;

  for(int i = 0; i < m; i ++ ) {
    int j = i;
    while(j < m - 1 && p[j + 1].dis == p[i].dis) {
      // debug(p[j].u, p[j].v);
      ++ j;
    }
    // debug(p[j].u, p[j].v);
    for(int k = i; k <= j; k ++ ) {
      auto [u, v, dis] = p[k];
      chkmax(f[u], g[v] + 1);
      chkmax(f[v], g[u] + 1);
      if(u == id) {
        debug(v, g[v], f[id]);
      } else if(v == id) {
        debug(u, g[u], f[id]);
      }
    }

    for(int k = i; k <= j; k ++ ) {
      auto [u, v, dis] = p[k];
      g[u] = f[u];
      g[v] = f[v];
    }
    // cout << "\n";

    // debug(i, j, p[i].u, p[i].v, p[j].u, p[j].v);
    // for(int k = 0; k <= n; k ++ ) {
    //   cout << f[k] << " \n"[k == n];
    // }

    i = j;
    
    //i - j的所有的都是需要更新的
  }
  cout << max(f[0] - 1, 1) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}