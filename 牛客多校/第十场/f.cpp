#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}

void solve() {
  int n, m, s, t; cin >> n >> m >> s >> t;
  vector<vector<int>> edg(n + 10, vector<int>(n + 10));
  while(m --){
    int u, v; cin >> u >> v;
    edg[u][v] ++, edg[v][u] ++;
  }
  vector<bool> st(n + 10);
  queue<int> q; q.push(t), st[t] = 1;
  while(q.size()){
    int u = q.front(); q.pop();
    for(int v = 1; v <= n; v ++){
      if(st[v] || edg[u][v] < 2) continue;
      st[v] = 1; q.push(v);
    }
  }
  if(st[s]) cout << "Join Player";
  else cout << "Cut Player";
}
