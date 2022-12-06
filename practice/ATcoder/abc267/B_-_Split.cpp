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
  if (s[0] == '1') {
    cout << "No\n";
    return ;
  }

  vector<vector<int> > a(7);
  a[0].push_back(7);
  a[1].push_back(4);
  a[2].push_back(8);a[2].push_back(2);
  a[3].push_back(5);a[3].push_back(1);
  a[4].push_back(9);a[4].push_back(3);
  a[5].push_back(6);
  a[6].push_back(10);
  
  auto chk = [&] (int x) {
    for (int p: a[x]) {
      if (s[p - 1] == '1') return true;
    }
    return false;
  };

  for (int i = 0; i < 7; i ++ ) if (chk(i)) {
    for (int j = i + 2; j < 7; j ++ ) if (chk(j)) {
      for (int k = i + 1; k < j; k ++ ) {
        bool flag = true;
        for (auto x: a[k]) if (s[x - 1] == '1') {
          flag = false;
        }
        if (flag) {
          cout << "Yes\n";
          return ;
        }
      }
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}