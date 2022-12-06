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

constexpr int N = 2E5 + 10;

int a[N];
bool vis[N];

void solve1() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];

  int A = -1, B = 1E9 + 1;

  for (int i = 1; i <= n; i ++ ) {
    if (a[i] <= A && a[i] >= B) {
      cout << "NO\n";
      return ;
    } else if (a[i] > A && a[i] < B) {
      if (i != n && a[i + 1] > a[i]) {
        A = a[i];
        vis[i] = true;
      } else {
        B = a[i];
      }
    } else if (a[i] > A) {
      vis[i] = true;
      A = a[i];
    } else {
      B = a[i];
    }
  }

  cout << "YES\n";

  for (int i = 1; i <= n; i ++ ) cout << (!vis[i]) << " \n"[i == n];

}

int f[N][2], g[N][2];
int in[N];

void solve2() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  // f[i][0]表示把序列的前i个数字拆分一个递增序列和一个递减序列(可以为空
  // 并且 A_i 属于递增序列时，递减序列结尾可能的最大值。 
  // f[i][1]表示把序列的前i个数字拆分一个递增序列和一个递减序列(可以为空
  // 并且 A_i 属于递减序列时，递增序列结尾可能的最小值。 

  // 转移有四种
  // a_{i-1} 和 a_i 都属于递增序列,条件是 a_{i-1} < a_i, f[i-1][0] -> f[i][0]
  // a_{i-1} 和 a_i 都属于递减序列,条件是 a_{i-1} > a_i, f[i-1][1] -> f[i][1]

  // a_{i-1} 属于递减序列 和 a_i 递增序列,条件是 f[i-1][1] < a[i] ,  a[i-1]->f[i][0]
  // a_{i-1} 属于递增序列 和 a_i 递减序列 条件是 f[i-1][0] > a[i] ,  a[i-1] -> f[i][1]

  f[1][0] = N, f[1][1] = -1;

  for (int i = 2; i <= n; i ++ ) {
    f[i][0] = -1, f[i][1] = N;
    if (a[i - 1] < a[i]) {
      f[i][0] = f[i - 1][0];
      g[i][0] = 0;
    }
    if (a[i - 1] > a[i]) {
      f[i][1] = f[i - 1][1];
      g[i][1] = 1;
    }
    if (f[i - 1][1] < a[i]) {
      // chkmax(f[i][0], )
      if (f[i][0] < a[i - 1]) {
        f[i][0] = a[i - 1];
        g[i][0] = 1;
      }
    }
    if (f[i - 1][0] > a[i]) {
      if (f[i][1] > a[i - 1]) {
        f[i][1] = a[i - 1];
        g[i][1] = 0;
      }
    }
  }
  if (~f[n][0] || f[n][1] < N) {
    cout << "YES\n";
    in[n] = ~f[n][0] ? 0 : 1;
    for (int i = n; i >= 2; i -- ) {
      in[i - 1] = g[i][in[i]];
    }
    for (int i = 1; i <= n; i ++ ) cout << in[i] << " \n"[i == n];
  } else {
    cout << "NO\n";
  }

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve2();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
