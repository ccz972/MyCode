// need O2 to pass the problem
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

constexpr int N = 20;
constexpr int M = 1 << N;
int a[N];
int f[M], s[M];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, w; cin >> n >> w;
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for(int i = 0; i < n; i ++ ) cin >> a[i];
  
  for(int i = 0; i < 1 << n; i ++ ) {
    for(int j = 0; j < n; j ++ ) if(i & (1 << j)) {
      s[i] += a[j];
    }
  }

  for(int i = 1; i < 1 << n; i ++ ) {
    for(int j = i; j; j = (j - 1) & i) {
      if(s[j] > w) continue;
      chkmin(f[i], f[i ^ j] + 1);
    }
  }

  cout << f[(1 << n) - 1] << "\n";

  return 0;
}