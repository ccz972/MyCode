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

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; i ++ ) {
    cin >> s[i];
  }

  array<int, 2> pos = {0, 0};
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < s[i].size(); j ++ ) {
      if(s[pos[0]][pos[1]] < s[i][j]) {
        pos = {i, j};
      }
    }
  }


  auto dfs = [&] (array<int, 2> p) {
    string ans;
    //  res; 
    // res.push_back(s[p[0]][p[1]]);



    for(int i = 0; i < 8; i ++ ) {
      int x = p[0], y = p[1];
      string res; res.push_back(s[p[0]][p[1]]);
      for(int j = 0; j < n - 1; j ++ ) {
        x += dx[i], y += dy[i];
        x = (x + n) % n, y = (y + n) % n;
        res.push_back(s[x][y]);
      }
      ans = max(ans, res);
      // return ans;
    }
    return ans;

  };

  string ans(n, '0');
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < n; j ++ ) {
      if(s[pos[0]][pos[1]] == s[i][j]) {
        ans = max(ans, dfs({i, j}));
      }
    }
  }
  cout << ans << "\n";

  

  return 0;
}