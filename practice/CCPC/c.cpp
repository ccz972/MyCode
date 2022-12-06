#include <bits/stdc++.h>
using namespace std;
#define pow2(x) (1ll * (x) * (x))
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, h; cin >> n >> m >> h;
  vector<int> f(m + 1);
  for (int i = 1; i <= m; i ++ ) cin >> f[i];
  vector<int> l(n + 1);
  for (int i = 1; i <= n; i ++ ) cin >> l[i];
  vector<vector<int> > t(n + 1, vector<int> (m + 1));
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      cin >> t[i][j];
      if (t[i][j]) {
        t[i][j] = min(l[i], f[j]);
      } 
      cout << t[i][j] << " \n"[j == m];
    }
  }
  
  
  return 0;
}