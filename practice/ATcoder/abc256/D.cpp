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

void solve() {
  int n; cin >> n;
  vector<int> s(200010);
  for(int i = 1; i <= n; i ++ ) {
    int l, r; cin >> l >> r;
    s[l] ++; s[r] --;
  }
  int now = -1;
  rep(i, 1, 200000) {
    s[i] += s[i - 1];
    if(s[i] == 0) {
      if(now != -1) {
        cout << now << " " << i << "\n";
      } 
      now = -1;
    }
    if(s[i] > 0) {
      if(now == -1)  now = i;
    }
  }
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}