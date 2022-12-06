#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int P = 1E9 + 7;
constexpr int N = 1010;


int f[N][N];
int s[N][N];
char str[N];

void solve() {
  int n = strlen(str + 1);

  for (int i = 0; i <= n + 5; i ++ ) {
    for (int j = 0; j <= n + 5; j ++ ) {
      f[i][j] = s[i][j] = 0;
    }
  }

  f[0][1] = 1;
  s[0][1] = 1;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= i + 1; j ++ ) {
      if (str[i] != 'D') f[i][j] = (f[i][j] + s[i - 1][j - 1]) % P;
      if (str[i] != 'I') f[i][j] = ((f[i][j] + ((s[i - 1][i] - s[i - 1][j - 1]) % P)) + P) % P;
    }
    for (int j = 1; j <= i + 1; j ++ ) {
      // printf("%d%c", s[i][j], " \n"[j == i + 1]);
      s[i][j] = (s[i][j - 1] + f[i][j]) % P;

    }
  }
  printf("%d\n", s[n][n + 1]);
}
int main() {
  while (scanf("%s", str + 1) != EOF)
  solve();
  return 0;
}
