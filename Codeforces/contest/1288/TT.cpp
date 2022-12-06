#include <cstdio>
#define MAXN 1005
#define int long long
#define mod 1000000007
using namespace std;
int n, m, dp[2][MAXN][MAXN], sum[2][MAXN][MAXN];
// dp[i][j][k] i=length,j=ai,k=bi (k>=j)
// dp[i][j][k]=sum(dp[i-1][1~j][k~n])
signed main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) dp[1][i][j] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      sum[1][i][j] = sum[1][i - 1][j] + sum[1][i][j - 1] -
                     sum[1][i - 1][j - 1] + dp[1][i][j];
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j <= n; j++)
      for (int k = j; k <= n; k++) {
        dp[i & 1][j][k] = sum[(i - 1) & 1][j][n] - sum[(i - 1) & 1][j][k - 1] -
                          sum[(i - 1) & 1][0][n] + sum[(i - 1) & 1][0][k - 1];
        dp[i & 1][j][k] %= mod;
      }
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        sum[i & 1][j][k] = sum[i & 1][j - 1][k] + sum[i & 1][j][k - 1] -
                           sum[i & 1][j - 1][k - 1] + dp[i & 1][j][k];
  }
  printf("%lld", (sum[m & 1][n][n] % mod + mod) % mod);
}