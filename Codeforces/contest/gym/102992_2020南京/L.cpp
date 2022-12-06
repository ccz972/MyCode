#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 


void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  map<int, int> mp;
  for (int &x: a) cin >> x;
  for (int &x: b) cin >> x, mp[x] ++ ;
  vector<pair<int, int> > p;
  rep(i, 1, n) if (!mp.count(a[i - 1])) {
    p.emplace_back(a[i - 1], 0);
  }
  rep(i, 1, m) {
    p.emplace_back(b[i - 1], 1);
  }
  p.emplace_back(-1000000001, 1);
  p.emplace_back(1000000001, 1);
  sort(all(p));
  n = p.size();
  int ans = 0;
  for (int i = 0; i < n; i ++ ) if (p[i].second == 1) {
    int j = i;
    while (j + 1 < n && p[j + 1].second == 0) {
      ++ j;
    }
    ans = max(ans, j - i);
    i = j;
  }
  if(!ans) cout << "Impossible\n";
  else cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T -- )
  solve();
  return 0;
}