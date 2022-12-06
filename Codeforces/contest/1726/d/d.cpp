/* Generated by powerful Codeforces Tool
 * Author: SmartNanfeng
 * Time: 2022-09-06 22:35:02
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for (int i(a); i <= b; i ++ )

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
// mt19937 rnd(random_device{}()); 
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct DSU {
  vector<int> f, siz, rank;
  int cnt; //统计还剩多少个连通块
  DSU(int n) : cnt(n), f(n), rank(n, 0), siz(n, 1) { iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return -1;
    else -- cnt;
    if(rank[x] > rank[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
    return y;
  }
  int size(int x) { return siz[find(x)]; }
}; //按秩合并 and 路径压缩 
 
void solve1() {
  int n, m; cin >> n >> m;
  
  vector<pair<int, int> > edge(m + 1);
  rep (i, 1, m) {
    int u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    
    edge[i] = make_pair(u, v);
  }
  if (m == n - 1) {
    rep (i, 1, m) cout << 0;
    cout << "\n";
    return ;
  } else if (n == m || n + 1 == m) {
    DSU d(n + 1);
    rep (i, 1, m) {
      auto [u, v] = edge[i];
      if (d.same(u, v)) {
        cout << 1;
      } else {
        cout << 0;
        d.merge(u, v);
      }
    }
    cout << "\n";
  } else {
    vector<int> last;
    DSU d(n + 1);
    rep (i, 1, m) {
      auto [u, v] = edge[i];
      if (d.same(u, v)) {
        last.emplace_back(i);
      } else {
        d.merge(u, v);
      }
    }

    auto chk = [&] () {
      vector<pair<int, int> > edg;
      for (int i : last) {
        edg.push_back(edge[i]);
      }
      sort(edg.begin(), edg.end());
      auto [u0, v0] = edg[0];
      auto [u1, v1] = edg[1];
      auto [u2, v2] = edg[2];
      set<int> s{u0, v0, u1, v1, u2, v2};
      if ((int)s.size() == 3) {
        return false;
      } else {
        return true;
      }
    };

    if (chk()) {
      rep (i, 1, m) { 
        bool flag = true;
        rep (j, 0, 2) if (i == last[j]) {
          flag = false;
        }
        if (flag) cout << 0;
        else cout << 1;
      }
      cout << "\n";
    } else {
      auto [root, aid] = edge[last[0]];
      vector<vector<pair<int, int> > > son(n + 1);
      rep (i, 1, m) {
        bool flag = true;
        rep (j, 0, 2) if (i == last[j]) {
          flag = false;
        }
        if (!flag) continue;
        auto [u, v] = edge[i];
        son[u].push_back(make_pair(v, i));
        son[v].push_back(make_pair(u, i));
      }
      // 以 u 为根 找 v
      function<bool(int, int)> dfs = [&] (int u, int fa) {
        bool flag = false;
        for (auto [v, id]: son[u]) if (v != fa) {
          if (v == aid) return true;
          flag |= dfs(v, u);
        }
        return flag;
      };

      for (auto [v, id] : son[root]) {
        if (dfs(v, root)) {
          rep (i, 1, m) {
            bool flag = true;
            rep (j, 1, 2) if (i == last[j]) {
              flag = false;
            }
            if (!flag || i == id) {
              cout << 0;
            } else {
              cout << 1;
            }
          }
          cout << "\n";
          break;
        }
      }
      // 需要找到树上 [u, v] 的路径的一条边

    }
  }
}

void solve2() {
  int n, m; cin >> n >> m;
  
  vector<array<int, 3>> edge(m + 1);
  rep (i, 1, m) {
    int u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    
    edge[i] = {u, v, i};
  }
  if (m == n - 1) {
    rep (i, 1, m) cout << 0;
    cout << "\n";
    return ;
  } else if (n == m || n + 1 == m) {
    DSU d(n + 1);
    rep (i, 1, m) {
      auto [u, v, id] = edge[i];
      if (d.same(u, v)) {
        cout << 1;
      } else {
        cout << 0;
        d.merge(u, v);
      }
    }
    cout << "\n";
  } else {
    vector<int> ans(m + 1);
    vector<int> idx(m + 1);
    iota(idx.begin(), idx.end(), 0);
    while (true) {
      shuffle(idx.begin() + 1, idx.end(), rnd);
      vector<int> last;
      DSU d(n + 1);
      rep (i, 1, m) {
        auto [u, v, id] = edge[idx[i]];
        if (d.same(u, v)) {
          last.emplace_back(id);
        } else {
          d.merge(u, v);
        }
      }
      auto chk = [&] () {
        vector<pair<int, int> > edg;
        for (int i : last) {
          edg.push_back(make_pair(edge[i][0], edge[i][1]));
        }
        sort(edg.begin(), edg.end());
        auto [u0, v0] = edg[0];
        auto [u1, v1] = edg[1];
        auto [u2, v2] = edg[2];
        set<int> s{u0, v0, u1, v1, u2, v2};
        if ((int)s.size() == 3) {
          return false;
        } else {
          return true;
        }
      };
      if (chk()) {
      rep (i, 1, m) { 
          bool flag = true;
          rep (j, 0, 2) if (i == last[j]) {
            flag = false;
          }
          if (flag) cout << 0;
          else cout << 1;
        }
        cout << "\n";
        return ;
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1; cin >> T;
  while (T --) {
    if (T & 1) {
      solve1();
    } else {
      solve2();
    }
  }
  return 0;
}

/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
