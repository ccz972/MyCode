#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 310;
constexpr int M = 2E4 + 10;
constexpr int mid = 1E4 + 1;
constexpr int INF = 0x3f3f3f3f;

int a[N];
int f1[N][M + 1], f2[N][M + 1];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;

  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }

  if(!m) {
    cout << "0\n";
    return 0;
  }

  m += mid;


  memset(f1, 0x3f, sizeof f1);

  f1[0][mid] = 0;

  for(int i = 1; i <= n; i ++ ) {
    int v = a[i];
    for(int j = 0; j <= M; j ++ ) {
      f1[i][j] = f1[i - 1][j];
      if(j >= v) {
        chkmin(f1[i][j], f1[i - 1][j - v] + 1);
      }
    }  
  } 

  int ans = f1[n][m];

  memset(f2, 0x3f, sizeof f2);

  f2[n + 1][mid] = 0;

  for(int i = n; i >= 1; i -- ) {
    int v = a[i];
    for(int j = 0; j <= M; j ++ ) {
      f2[i][j] = f2[i + 1][j];
      if(j >= v) {
        chkmin(f2[i][j], f2[i + 1][j - v] + 1);
      }
    }
  }


  for(int i = 1; i <= n; i ++ ) {

    for(int j = 0; j <= M; j ++ ) {
      int now = (j - mid) / 2;
      if(m - now < 0 || m - now > M) continue;
      chkmin(ans, f1[i][j] + f2[i + 1][m - now]);
    }

  }

  if(ans > n) ans = -1;
  cout << ans << "\n";


  return 0;
}