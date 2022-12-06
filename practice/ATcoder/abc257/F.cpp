#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  
  vector<int> all;

  vector<vector<int>> son(n + 1);
  for (int i = 0, u, v; i < m; i ++ ) {
    cin >> u >> v; 
    if (!u) {
      all.push_back(v);
    } else if(!v) {
      all.push_back(u);
    } else {
      son[u].push_back(v), son[v].push_back(u);
    }
  }
  
  vector<int> depth1(n + 1, -1), depth2(n + 1, -1);

  queue<int> q;

  depth1[1] = 0;
  depth2[n] = 0;

  q.push(1);
  vector<bool> st(n + 1, false);
  st[1] = true;

  while (q.size()) {
    int u = q.front(); q.pop();
    for (int &v: son[u]) if(!st[v]) {
      st[v] = true;
      depth1[v] = depth1[u] + 1;
      q.push(v);
    }
  }

  for (int i = 0; i <= n; i ++ ) {
    st[i] = false;
  }

  st[n] = true;
  q.push(n);

  while (q.size()) {
    int u = q.front(); q.pop();
    for (int &v: son[u]) if(!st[v]) {
      st[v] = true;
      depth2[v] = depth2[u] + 1;
      q.push(v);
    }
  }

  // function<void(int, int)> dfs1 = [&](int u, int fa) {
  //   for (auto& v : son[u]) if(fa != v && depth1[v] == -1) {
  //     depth1[v] = depth1[u] + 1;
  //     dfs1(v, u);
  //   }
  // };

  // function<void(int, int)> dfs2 = [&](int u, int fa) {
  //   for (auto& v : son[u]) if(fa != v && depth2[v] == -1) {
  //     depth2[v] = depth2[u] + 1;
  //     dfs2(v, u);
  //   }
  // };
  

  vector<array<int, 2> > v1, v2;

  for (int &x: all) {
    if (~depth1[x]) {
      v1.push_back({depth1[x], x});
    } 
    if(~depth2[x]) {
      v2.push_back({depth2[x], x});
    }
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  // auto find = 
  auto solve1 = [&] () {
    for (int i = 1; i <= n; i ++ ) {
      int ans = depth1[n];
      if (~depth1[i]) {
        if (!v1.empty() && !v2.empty()) {
          ans = min(ans, v1[0][0] + v2[0][0] + 2);
        }
        if (!v1.empty()) {
          ans = min(ans, depth2[i] + v1[0][0] + 1);
        }
        if (!v2.empty()) {
          ans = min(ans, depth1[i] + v2[0][0] + 1);
        }
      } else {
        if (!v1.empty() && !v2.empty()) {
          ans = min(ans, v1[0][0] + v2[0][0] + 2);
        } 
      }
      cout << ans << " ";
    }
  };

  auto solve2 = [&] () {
    for (int i = 1; i <= n; i ++ ) {
      if (~depth1[i]) {
        if (v2.empty()) {
          cout << "-1 ";
        } else {
          int ans = depth1[i] + v2[0][0] + 1;
          if (!v1.empty())
            ans = min(ans, v1[0][0] + 1 + v2[0][0] + 1);
          cout << ans << " ";
        }
      } else if(~depth2[i]) {
        if (v1.empty()) {
          cout << "-1 ";
        } else {
          int ans = depth2[i] + v1[0][0] + 1;
          if (!v2.empty())
            ans = min(ans, v1[0][0] + 1 + v2[0][0] + 1);
          cout << ans << " ";
        }
      } else {
        if (!v1.empty() && !v2.empty()) {
          cout << v1[0][0] + v2[0][0] + 2 << " ";
        } else {
          cout << "-1 ";
        }
      }
    }
  };

  if (~depth1[n] && ~depth2[1])
    solve1();
  else 
    solve2();

  return 0;
}