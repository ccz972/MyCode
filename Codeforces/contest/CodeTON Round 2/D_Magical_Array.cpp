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
/*
0,1,1,1,1,1,1,1,0

0 1 2 0 0 2 1 1 0
0 1 1 1 2 0 0 2 0
0 1 2 0 0 1 2 1 0


0 1 2 0 0 2 1 1 0 // !kw
0 1 2 0 0 1 2 1 0 //  k


[20,20,20,20,20,20,20]
25 15 20 15 25 20 20
26 14 20 14 26 20 20
25 15 20 15 20 20 25

20 20 20 15 25 20 20

2 0 0 2 1 1 
1 1 2 0 0 2
2 0     1  1  

*/


void solve() {
  int n, m; cin >> n >> m;
  vector<vector<ll> > a(n + 7, vector<ll>(m + 7, 0ll));
  vector<vector<ll> > s(n + 7, vector<ll>(m + 7, 0ll));
  
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      cin >> a[i][j]; a[i][j] += a[i][j - 1];
      s[i][j] = s[i][j - 1] + a[i][j];
    }
  }
  for(int i = 2; i <= n; i ++ ) {
    if(s[1][m] != s[i][m]) {
      if(i > 2) {
        cout << i << " " << s[1][m] - s[i][m] << "\n";
      } else {
        if(s[1][m] == s[3][m]) {
          cout << i << " " << s[1][m] - s[i][m] << "\n";
        } else {
          cout << "1 " << s[2][m] - s[1][m] << "\n";
        }
      }
      return;
    }
  }


  for(int i = 1; i < n; i ++ ) {
    vector<int> nxt(m, -1);
    int now = -1;
    for(int j = m - 1; j >= 0; j -- ) {
      if(a[i][j] != a[0][j]) {
        now = j;
      }
      nxt[j] = now;
    }
    int l = nxt[0], r = nxt[l + 1];    
  }

  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}