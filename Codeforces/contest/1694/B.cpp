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

void solve() {
  //0000001
  //111111110
  int n; cin >> n;
  ll ans = n;
  string s; cin >> s;
  reverse(s.begin(), s.end());
  for(int i = 0; i < n - 1; i ++ ) {
    if(s[i] != s[i + 1]) {
      ans += n - i - 1;
    }
  } 
 

  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}