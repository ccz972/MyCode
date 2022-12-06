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

constexpr int N = 24, M = (1 << 24) + 1;
constexpr int p = 1e9 + 7;

ll f[M], sum[M], no[3];
#define lowbit(x) ((x & -x))
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  for(int i = 0; i < n; i ++ ) {
    int x; cin >> x;
    sum[1 << i] = x;
  }
  int k; cin >> k;
  for(int i = 1; i <= k; i ++ ) cin >> no[i];
  f[0] = 1;
  for(int i = 1; i < 1 << n; i ++ ) {
    sum[i] = sum[i & ~lowbit(i)] + sum[lowbit(i)];
    if(sum[i] == no[1] || sum[i] == no[2]) continue;
    for(int j = i; j; j -= lowbit(j)) {
      f[i] += f[i & ~lowbit(j)];
      while(f[i] >= p) f[i] -= p;
    }
  }
  cout << f[(1 << n) - 1];
  return 0;
}