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

constexpr int N = 30, M = 1 << 13;

int n, m, ans, s1, s2, es;  
int p[N];
int f[M];

void dfs(int x, int k, int sum) {
  if(k == n / 2) {
    if(sum < ans) {
      ans = sum, es = s1;
    }
    return ;
  }

  for(int i = x + 1; i < n; i ++ ) {
    int sum1 = __builtin_popcount(s1 & p[i]), sum2 = __builtin_popcount(s2 & p[i]);
    s1 ^= (1 << i);
    s2 ^= (1 << i);
    dfs(i, k + 1, sum - sum1 + sum2);
    s1 ^= (1 << i);
    s2 ^= (1 << i);
  }

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;

  for(int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v;
    u --, v --;
    p[u] |= 1 << v;
    p[v] |= 1 << u;
  }
  s2 = (1 << n) - 1;
  ans = INT_MAX;
  dfs(-1, 0, 0);
  for(int i = 0; i < n; i ++ ) if(es >> i & 1) {
    cout << i + 1 << " ";
  }

  return 0;
}