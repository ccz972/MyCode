// @created by Nanfeng1997
// @url https://www.luogu.com.cn/problem/P2657

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


const int N = 3e5 + 10;

// ll f[N][15];
// ll g[N];
// void solve() {
//   int m, t; ll s; cin >> m >> s >> t;
//   int st = m / 10;

//   memset(f, -1, sizeof f);
//   f[st][m % 10] = st * 60;
  
//   if(st * 60 >= s) {
//     cout << "Yes\n" << (s + 59) / 60 << "\n";
//     return ;
//   }
//   if(st >= t) {
//     cout << "No\n" << t * 60 << "\n";
//     return ;
//   }
//   for(int i = st; i < t; i ++ ) {
//     for(int j = 0; j <= 14; j ++ ) if(~f[i][j]) {
//       if(j < 10) { // hui fu
//         chkmax(f[i + 1][j + 4], f[i][j]);
//       } else {
//         chkmax(f[i + 1][j % 10], f[i][j] + 60);
//       }
//       chkmax(f[i + 1][j], f[i][j] + 17);
//       chkmax(g[i], f[i][j]);
//     }
//   }
//   for(int i = 0; i <= 14; i ++ ) {
//     chkmax(g[t], f[t][i]);
//   }
//   for(int i = 1; i <= t; i ++ ) {
//     if(g[i] >= s) {
//       // cout << g[i] << "\n";
//       cout << "Yes\n" << i << "\n";
//       return ;
//     }
//   }
//   cout << "No\n" << g[t] << "\n";
// }

void solve() {
  int m, t; ll s; cin >> m >> s >> t;
  ll s1 = 0, s2 = 0; // walk    shanxian
  for(int i = 1; i <= t; i ++ ) {
    s1 += 17;
    if(m >= 10) s2 += 60, m -= 10;
    else m += 4;
    chkmax(s1, s2);
    if(s1 >= s) {
      cout << "Yes\n" << i << "\n";
      return ;
    }
  }
  cout << "No\n" << s1 << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}