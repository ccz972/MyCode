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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;
  map<char, int> mp1, mp2;
  for(char c: s) mp1[c] ++;
  for(char c: t) mp2[c] ++;
  int cnt = 0;
  for(auto [k, v]: mp1) {
    cnt += v & 1;
  }
  int cnt2 = 0;
  for(auto [k, v]: mp1) {
    cnt2 += v & 1;
  }
  cout << cnt1 << "\n";
  if(cnt < cnt1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}