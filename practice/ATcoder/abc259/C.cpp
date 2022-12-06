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
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<pair<char, int> > a1, a2;
  for(int i = 0; i < n; i ++ ) {
    int j = i;
    while(j + 1 < n && s[j + 1] == s[i]) {
      ++ j;
    }
    a1.push_back({s[i], j - i + 1});
    i = j;
  }

  for(int i = 0; i < m; i ++ ) {
    int j = i;
    while(j + 1 < m && t[j + 1] == t[i]) {
      ++ j;
    }
    a2.push_back({t[i], j - i + 1});
    i = j;
  }
  
  if(a1.size() != a2.size()) {
    cout << "No\n";
    return 0;
  }

  n = a1.size();
  for(int i = 0; i < n; i ++ ) {
    auto [k1, v1] = a1[i];
    auto [k2, v2] = a2[i];
    if(k1 != k2 || (v1 == 1 && v2 > v1) || v1 > v2)  {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  // for(int i = 0; i < n; i ++ )
  // for(int i = 0; i < n; i )

  return 0;
}