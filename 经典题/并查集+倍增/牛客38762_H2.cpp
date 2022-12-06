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

constexpr int N = 2E5 + 10;

int fa[N][20];

int find(int x, int k) {
  if (fa[x][k] != x) fa[x][k] = find(fa[x][k], k);
  return fa[x][k];
}

void merge(int x, int y, int k) {
  x = find(x, k), y = find(y, k);
  if (x != y) fa[x][k] = y;
}

void solve() {
  int n, m; cin >> n >> m;
  int bit = __lg(n * 2);
  for (int i = 1; i <= n * 2; i ++ ) {
    for (int j = 0; j <= bit; j ++ ) {
      if (j == 0)
        fa[i][j] = i <= n ? i : 2 * n - i + 1;
      else 
        fa[i][j] = i;
    }
  }
  while (m -- ) {
    int l1, r1; cin >> l1 >> r1;
    int l2 = 2 * n - r1 + 1, r2 = 2 * n - l1 + 1;
    for (int k = bit; k >= 0; k -- ) {
      if (l1 + (1 << k) - 1 <= r1) {
        merge(l1, l2, k);
        l1 += 1 << k;
        l2 += 1 << k;
      }
    }
  }
  for (int k = bit; k >= 1; k -- ) {
    for (int i = 1; i + (1 << k) - 1 <= 2 * n; i ++ ) {
      int pos = find(i, k);
      merge(i, pos, k - 1);
      merge(i + (1 << k - 1), pos + (1 << k - 1), k - 1);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i ++ ) if (find(i, 0) == find(n + i, 0)) {
    ++ cnt;
  }
  if (cnt == n)
    cout << "YES\n";
  else 
    cout << "NO\n";
  
  cout << cnt << "\n";

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
