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
  int n; cin >> n;
  string s; cin >> s;
  // map<char, char> mp, fmp;
  string t;
  vector<int> nxt(26, -1);
  // for (int i = 0; i < 26; i ++ ) nxt[i] = i;
  //x -> y -> z     p->q
  vector<bool> used(26, false);
  int cnt = 0;
  for (int i = 0; i < n; i ++ ) {
    if (~nxt[s[i] - 'a']) {
      t += (char)('a' + nxt[s[i] - 'a']);
    } else {
      ++ cnt;
      int now = s[i] - 'a';
      //nxt[now] = ?
      for (int j = 0; j < 26; j ++ ) if (not used[j]) {
        //nxt[now] = j ?
        nxt[now] = j;
        int k = now;
        for (int tim = 0; tim < 26; tim ++ ) {
          k = nxt[k];
          if (k == -1) break;
        }
        if (k == -1 || cnt == 26) {
          nxt[now] = j;
          used[j] = true;
          break;
        }
      }

      t += (char)('a' + nxt[s[i] - 'a']);
    }
    // debug(nxt);
  }
  cout << t << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}