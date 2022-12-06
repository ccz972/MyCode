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
  //求多少个集合是其他集合的 真子集
  int n; cin >> n;
  map<int, array<int, 2> > mp;
  vector<vector<pair<int, int> > > a(n); 
  for(int i = 0; i < n; i ++ ) {
    int m; cin >> m;
    for(int j = 0; j < m; j ++ ) {
      int p, e; cin >> p >> e;
      a[i].push_back({p, e});
      if(e > mp[p][0]) {
        mp[p][1] = mp[p][0];
        mp[p][0] = e;
      } else {
        chkmax(mp[p][1], e);
      }
    }
  }
  

  vector<vector<pair<int, int> > > pp; 

  for(int i = 0; i < n; i ++ ) {
    vector<pair<int, int> > now;
    for(auto &[p, e]: a[i]) if(e == mp[p][0]) {
      int v = mp[p][1];
      if(v != e) now.push_back({p, v - e}); //计算减去这个的贡献
    }
    sort(now.begin(), now.end());

    pp.push_back(now);
  }

  sort(pp.begin(), pp.end());
  int ans = unique(pp.begin(), pp.end()) - pp.begin();

  cout << ans << "\n";


  return 0;
}