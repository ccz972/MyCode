#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> m >> n;
  // vector<int> v(m), w(m);
  vector<array<int, 3> > a(n);
  // vector<int>
  vector son(n, vector<int>()); 
  for (int i = 0; i < n; i ++ ) {
    auto &[v, w, father] = a[i];
    cin >> v >> w >> father;
    w *= v;
    // cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";
    if(father)
      son[father - 1].push_back(i);
  }

  vector<int> f(m + 1);

  for (int i = 0; i < n; i ++ ) {
    auto [v, w, father] = a[i];
    if(father) continue;
    // cout << i << "\n";
    
    for (int j = m; j >= 0; j -- ) {
      
      for(int k = 0; k < (1 << son[i].size()); k ++ ) {
        int V = v, W = w;
        for(int p = 0; p < son[i].size(); p ++ ) if(k >> p & 1) {
          V += a[son[i][p]][0], W += a[son[i][p]][1];
        }
        if(j >= V) f[j] = max(f[j], f[j - V] + W);
      }
    }
  }
  cout << f.back();

  return 0;
}