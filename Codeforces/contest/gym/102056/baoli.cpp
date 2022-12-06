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

int a[101], b[101], c[101];
int n ; 
ll ans = 0;
void dfs(int now, int A, int D, ll x) {
  if(now == n + 1) {
    if(x == 31)
    cout << A << " " << D << "\n";
    chkmax(ans, x);
    return ;
  }
  //case:1
  dfs(now + 1, A + D, D, x + A + a[now]);
  dfs(now + 1, A + D + b[now], D + b[now], x);
  dfs(now + 1, A + D + c[now], D, x);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i] >> b[i] >> c[i];
  }  
  dfs(1, 0, 0, 0);
  cout << ans << "\n";
  //3 1 2

  return 0;
}