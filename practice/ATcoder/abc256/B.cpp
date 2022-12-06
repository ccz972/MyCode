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

inline void out(bool flag) {
  cout << (flag ? "Yes" : "No" ) << "\n";
}
int a[110];
int p[100];
void solve() {
  int n; cin >> n;
  int ans = 0;

  rep(i, 1, n) {
    int x; cin >> x;
    p[0] ++;
    for(int j = 3; j >= 0; j -- ) {
      if(j + x < 4) {
        p[j + x] += p[j];
        p[j] = 0;
      } else {
        ans += p[j];
        p[j] = 0;
      }
    } 
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}