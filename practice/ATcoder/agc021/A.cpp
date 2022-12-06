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
  string s; cin >> s;
  int cnt = 0;
  for(char c: s) cnt += (c == '9');
  if (cnt == (int)s.size()) {
    cout << cnt * 9;
  } else  {
    int ans = 0;
    for(char c: s) ans += (c - '0');
    int n = s.size();
    int now = 0;
    for(int i = 0; i < n - 1; i ++ ) if(s[i] != '0') {
      ans = max(ans, now + (s[i] - '1') + (n - i - 1) * 9);
      now += (s[i] - '0');
    }
    cout << ans;
  } 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}