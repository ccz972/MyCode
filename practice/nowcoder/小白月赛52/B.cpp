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
  string s;
  cin >> s;
  int n = s.size();
  int add = 0;
  for(int i = n - 1; i >= 0; i -- ) {
    int now = s[i] - '0';
    if(now + add >= 5) {
      // s[i] = '0';
      // cout << ": > " << i << "\n";
      for(int j = i; j < n; j ++ ) s[j] = '0';
      // cout << s << "\n";
      add = 1;
    } else {
      s[i] += add;
      add = 0;
    }
  }
  if(add) {
    cout << "1";
  }
  cout << s << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}