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
  int p; cin >> p;
  vector<vector<char> > a(4 * p + 5, vector<char>(13 * p + 19, '.'));
  int n = 4 * p + 5, m = 13 * p + 19;
  for(int i = 0; i < m; i ++ ) {
    a[0][i] = a[n - 1][i] = '*';
  }
  for(int i = 0; i < n; i ++ ) {
    a[i][0] = a[i][m - 1] = '*';
  }
  for(int i = p + 1, k = 0; k < 2 * p + 3; i ++, k ++ ) {
    a[i][p + 2] = '@';
  } //(p + 1, p + 2)

  array<int, 2> idx;
  for(int i = p + 1, j = p + 2, k = 0; k < 2 * p + 3; k ++, i ++, j ++ ) {
    a[i][j] = '@';
    idx = {i, j};
  } 
  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[0] --;
  }
  idx[0] ++;
  idx[1] += p + 2;
  auto tmp = idx;
  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[0] ++;
  }

  idx = tmp;

  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[1] ++;
  }

  idx = tmp;
  idx[0] += p + 1;

  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[1] ++;
  }

  idx[0] = tmp[0];
  idx[1] --;
  idx[1] += p + 2;
  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[0] ++;
  }
  idx[0] --;
  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[1] ++;
  }

  idx[1] += p + 1;

  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[1] ++;
  }
  idx[1] --;
  for(int i = 0; i < p + 2; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[0] --;
  }
  idx[0] ++;
  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[1] --;
  }

  idx[1] ++;

  for(int i = 0; i < p + 2; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[0] --;
  }
  idx[0] ++;
  for(int i = 0; i < 2 * p + 3; i ++ ) {
    a[idx[0]][idx[1]] = '@';
    idx[1] ++;
  }

  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < m; j ++ ) {
      cout << a[i][j];
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}