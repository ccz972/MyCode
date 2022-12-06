#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 


void solve() {
  int n; cin >> n;
  vector<vector<int>> edg(n + 1);
  vector<int> tag(n + 1), h(n + 1), val(n + 1);


  for(int v = 2; v <= n; v ++){
    int u; cin >> u;
    edg[u].push_back(v);
  }
  for(int i = 1; i <= n; i ++) cin >> h[i];

  int mxx = -1, id = 1; tag[0] = 1;
  int res = 0;

  function<void(int, int u)> dfs = [&](int fa, int u){
    if(!tag[u]){
      int tmp = h[u];
      if(!tag[fa]) tmp += h[u];
      for(int v : edg[u]) {
        if(!tag[v]) tmp += h[v];
      }
      if(mxx < tmp) id = u, mxx = tmp;      
      if(!tag[fa]) tmp -= h[u];
      res += tmp;
    } 
    //cout << u << ' ' << res << endl;
    for(int v : edg[u]){
      dfs(u, v);
    }
  };

  dfs(0, 1); 
  // cout << res << ' ';
  
  for(int i = 1; i <= n; i ++){
    tag[id] = 1, mxx = 0, id = 0, res = 0;
    dfs(0, 1); 
    // cout << res << ' ';
    for(int i=1;i<=n;i++)
      if(!tag[i])
        cout<<i<<" ";
    cout<<'\n';
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T --) solve();
  return 0;
}