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


constexpr int N = 2001;

int a[N][N];

void dfs (int n) {
  if (n == 2) {
    // for (int i = )
    a[0][0] = a[0][1] = a[1][0] = 1;
    a[1][1] = -1;
    return ;
  }
  dfs (n / 2);
  for (int i = 0; i < n / 2; i ++ ) {
    for (int j = n / 2; j < n; j ++ ) {
      a[i][j] = a[i][j - n / 2];
    }
  }
  for (int i = n / 2; i < n; i ++ ) {
    for (int j = 0; j < n / 2; j ++ ) {
      a[i][j] = a[i - n / 2][j];
    }
    for (int j = n / 2; j < n; j ++ ) {
      a[i][j] = -a[i - n / 2][j - n / 2];
    }
  }
}

void solve2() {
  int n; cin >> n;
  dfs (n);
  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < n; j ++ ) {
      cout << a[i][j] << " \n"[j == n - 1];
    }
  }

  // for (int i = 0; i < n; i ++ ) {
  //   for (int j = i + 1; j < n; j ++ ) {
  //     int cnt = 0;
  //     for (int k = 0; k < n; k ++ ) {
  //       cnt += (a[i][k] == a[j][k] && a[i][k] == -1);
  //     }
  //     if (cnt != n / 4) cout << i << " " << j << " " << "FUCK\n";
  //   }
  // }
  
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve2();
  return 0;
}