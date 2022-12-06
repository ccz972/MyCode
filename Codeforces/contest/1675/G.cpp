#include <bits/stdc++.h>
using namespace std;

constexpr int N = 252;

int a[N], s[N], f[N][N][N];
template < typename T > 
inline void chkmax(T &x, T y) {x = x >= y ? x : y;}
template < typename T > 
inline void chkmin(T &x, T y) {x = x <= y ? x : y;}
int main() {
  int n, m; scanf("%d%d", &n, &m);
  //f[i][j][k], 第i个箱子有j个球，并且前i个箱子有k个
  for (int i = n; i >= 1; i -- ) scanf("%d", a + i);
  for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];

  memset(f, 0x3f, sizeof f);
  f[0][0][0] = 0;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 0; j <= m; j ++ ) {
      int mi = 1 << 30;
      for (int k = 0; j + k <= m; k ++ ) {
        chkmin(mi, f[i - 1][j][k]);
        chkmin(f[i][j + k][k], mi + abs(s[i] - j - k));
      }
    }
  }
  printf("%d\n", *min_element(f[n][m], f[n][m] + m + 1));
  return 0;
}