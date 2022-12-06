#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)
#define YES cout << "YES" << "\n"; return  
#define NO  cout << "NO" << "\n";  return  

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 351, M = 41;

int n, m; 
int a[N];
int cnt[5];
int f[M][M][M][M];

int calc(array<int, 4> A) {
  int ret = 0;
  for(int i = 0; i < 4; i ++ ) {
    ret += (i + 1) * (cnt[i + 1] - A[i]);
  }
  debug(A, ret);
  return ret + 1;
}

int dfs(int x1, int x2, int x3, int x4) {
  if(!x1 && !x2 && !x3 && !x4) {
    return a[n];
  }
  int &ret = f[x1][x2][x3][x4];
  if(~ret) return ret;
  ret = a[calc({x1, x2, x3, x4})];
  int mx = 0;
  if(x1) chkmax(mx, dfs(x1 - 1, x2, x3, x4));
  if(x2) chkmax(mx, dfs(x1, x2 - 1, x3, x4));
  if(x3) chkmax(mx, dfs(x1, x2, x3 - 1, x4));
  if(x4) chkmax(mx, dfs(x1, x2, x3, x4 - 1));
  
  ret += mx;
  debug(x1, x2, x3, x4, ret);
  return ret;
}

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) {
    int x; cin >> x;
    cnt[x] ++;
  }
  memset(f, -1, sizeof f);
  // f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] = 0;
  cout << dfs(cnt[1], cnt[2], cnt[3], cnt[4]);  
  
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}