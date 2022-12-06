#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int mp[26][26];
void solve() {
  int n; cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;
  memset(mp, 0, sizeof mp);
  for (int i = 0; i < n; i ++ ) {
    char c1 = s[i], c2 = t[n - 1 - i];
    if (c1 > c2) swap(c1, c2);
    mp[c1 - 'a'][c2 - 'a'] ++;
  }
  bool flag = true;
  int cnt = 0;
  for (int i = 0; i < 26; i ++ ) {
    cnt += (mp[i][i] & 1);
    for (int j = i + 1; j < 26; j ++ ) {
      if (mp[i][j] & 1) {
        flag = false;
      }
    }
  }
  if (!flag || (cnt > (n & 1))) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
