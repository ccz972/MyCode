// SOLUTION : https://blog.csdn.net/xuxiayang/article/details/109036847
// url : https://www.luogu.com.cn/problem/UVA12991

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

constexpr int N = 1e5 + 10;
constexpr ll inf = 1e18;

int n, a[N][2];
ll f[N][2];
ll s1[N][2], s2[N][2], S1[N][2], S2[N][2];
int Case;

// inline LL order(int l,int r,bool k){return S1[r][k]-S1[l-1][k]-(l-1)*(s1[r][k]-s1[l-1][k]);}//order表示l到r都去到l-1，k表示是算a的和还是b的和
// inline LL rrder(int l,int r,bool k){return S2[l][k]-S2[r+1][k]-(n-r)*(s2[l][k]-s2[r+1][k]);}//rrder表示l到r都去到r+1，k表示是算a的和还是b的和


ll get1(int l, int r, int k) {
  return S1[r][k] - S1[l - 1][k] - 1ll * (l - 1) * (s1[r][k] - s1[l - 1][k]);
}

ll get2(int l, int r, int k) {
  return S2[l][k] - S2[r + 1][k] - 1ll * (n - r) * (s2[l][k] - s2[r + 1][k]);
}


ll cost(int l, int r, int k) {
  if(l == 1 && r == n) return inf;
  if(l == 1) return get2(l, r, k ^ 1);
  if(r == n) return get1(l, r, k ^ 1);
  int mid = (l + r) / 2;
  return get1(l, mid, k ^ 1) + get2(mid + 1, r, k ^ 1);
}

void solve() {

  cin >> n;
  
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i][0] >> a[i][1];
    for (int j = 0; j < 2; j ++ ) {
      f[i][j] = inf;
      s1[i][j] = s1[i - 1][j] + a[i][j];
      S1[i][j] = S1[i - 1][j] + 1ll * i * a[i][j];
    }
  }

  s2[n + 1][0] = s2[n + 1][1] = S2[n + 1][0] = S2[n + 1][1] = 0;
  for (int i = n; i >= 1; i -- ) {
    for (int j = 0; j < 2; j ++ ) {
      s2[i][j] = s2[i + 1][j] + a[i][j];
      S2[i][j] = S2[i + 1][j] + 1ll * (n - i + 1) * a[i][j];
    }
  }

  for (int i = 1; i <= n; i ++ ) {
    for (int j = 0; j < i; j ++ ) {
      for (int k = 0; k < 2; k ++ ) {
        chkmin(f[i][k], f[j][k ^ 1] + cost(j + 1, i, k));
      }
    }
  }  

  cout << "Case #" << ++ Case << ": " << min(f[n][0], f[n][1]) << "\n";
  
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();    
  }
  return 0;
}