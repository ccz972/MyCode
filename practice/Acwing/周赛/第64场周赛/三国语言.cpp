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
string a, b, c, d;
void solve() {
  string s; getline(cin, s);
  // for(int i = 0; i < s.size() && )
  int n = s.size();
  if(s.substr(max(0, n - 2), 2) == a) {
    cout << "FILIPINO\n";
  } else if(s.substr(max(0, n - 4), 4) == b || s.substr(max(0, n - 4), 4) == c){
    cout << "JAPANESE\n";
  } else {
    cout << "KOREAN\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  a = "po", b = "desu", c = "masu", d = "mnida";
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());
  reverse(d.begin(), d.end());
  int T = 1; cin >> T;
  getchar();
  while(T -- ) solve();
  return 0;
}