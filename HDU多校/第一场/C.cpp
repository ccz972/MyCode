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

constexpr int N = 1 << 11;

bitset<N> f[N];
bitset<N> g[N];

// bitset<N> now[N];

int main() {
  // freopen("1.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n, m; cin >> n >> m;
    for(int i = 0; i < N; i ++ ) f[i].reset(), g[i].reset();
    //f[j]表示价值为j的时候的所有体积和

    f[0][0] = 1, g[0][0] = 1;

    for(int i = 0; i < n; i ++ ) {
      int v, w; cin >> v >> w;
      // for(int j = 0; j < N; j ++ ) g[j] = f[j];
      for(int j = 0; j < (1 << 10); j ++ ) {
        g[j ^ w] |= (f[j] << v); 
      }      
      for(int j = 0; j < N; j ++ ) {
        f[j] = g[j];
      }
    }

    for(int i = 1023; i >= 0; i -- ) if(f[i][m]) {
      cout << i << "\n";
      return ;
    }
    cout << "-1\n";
  };
  


  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}