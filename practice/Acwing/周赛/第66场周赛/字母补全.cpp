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

void solve() {
  string s; cin >> s;
  // vector<int> cnt(26);
  bool have = false;
  int n = s.size();
  for(int i = 0; i < n; i ++ ) {
    auto t = s.substr(i, 26);
    if (t.size() != 26) break;
    vector<int> cnt(26, 0);
    for (char c: t) if (c != '?') cnt[c - 'A'] ++;
    bool flag = true;
    for (int i = 0; i < 26; i ++ ) if (cnt[i] > 1) {
      flag = false;
    }
    if (!flag) continue;
    have = true;
    for (int j = i; j < i + 26; j ++ ) if (s[j] == '?') {
      for (int k = 0; k < 26; k ++ ) if (!cnt[k]) {
        cnt[k] ++;
        s[j] = (char)('A' + k);
        break;
      }
    }
  }
  if (have) {
    for (char &c: s) if (c == '?') {
      c = 'A';
    }
    cout << s << "\n";
  } else {
    cout << "-1\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}