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

constexpr int N = 100;
int a[N][N], b[N][N];

void solve() {
  int n1, m1, n2, m2;
  cin >> n1 >> m1;
  rep(i, 1, n1) {
    rep(j, 1, m1) {
      cin >> a[i][j];
    }
  }
  cin >> n2 >> m2;
  rep(i, 1, n2) {
    rep(j, 1, m2) {
      cin >> b[i][j];
    }
  }

  for(int i = 0; i < 1 << n1; i ++ ) if(__builtin_popcount(i) == n2) {
    for(int j = 0; j < 1 << m1; j ++ ) if(__builtin_popcount(j) == m2){
      int x = 1;      
      bool flag = true;
      for(int k = 0; k < n1 && flag; k ++ ) if(i >> k & 1) {
        int y = 1;
        for(int l = 0; l < m1 && flag; l ++ ) if(j >> l & 1) {
          if(a[k + 1][l + 1] != b[x][y ++ ]) {
            flag = false;
          }
        }
        x ++;
      }
      if(flag) {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;// cin >> T;
  while(T -- ) solve();
  return 0;
}