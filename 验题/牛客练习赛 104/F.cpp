#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());


constexpr int N = 3E5 + 10;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

vector<int> son[N];

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> p(k + 1);
  ll sum = 0;
  for (int i = 1; i <= k; i ++ ) {
    p[i] = rnd() % INF;
    sum ^= p[i];
  }

  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  


  


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
