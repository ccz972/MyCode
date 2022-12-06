#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2E5 + 10;

// int d[N], cnt[N], inq[N];
vector<pair<int, int> > son[N];

void solve() {

  // 对于某条边 [u, v, w] 表示 从 u 到 v 至少要付出多少个 1
  // B_i 表示 A_1, A_2, ...,A_i 中 0 的个数
  // 要求 B_i 的最大值


  // B_i >= B_{i-1}                    ==> B_{i-1} <= B_i + 0
  // B_{i-1} + 1 >= B_i                ==> B_i     <= B_{i-1} + 1
  // r - l + 1 - (B_r - B_{l-1}) >= x
  //  (B_r - B_{l-1}) <= r - l + 1 - x ==> B_r <= B_{l-1} + r - l + 1 - x
  int n, m; 
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) {
    // son[i].emplace_back(i - 1, -1);  
    son[i - 1].emplace_back(i, 1);
    son[i].emplace_back(i - 1, 0);
  }

  while (m -- ) {
    int l, r, x;
    cin >> l >> r >> x;
    son[l - 1].emplace_back(r, r - l + 1 - x); // 最多可以得到多少个 0
  }
  
  vector<int> dist(n + 1, 1E9);
  vector<bool> st(n + 1, false);
  dist[0] = 0; 
  struct node {int ver, dist; bool operator < (const node &T) const {
    return dist > T.dist;
  }};
  priority_queue<node> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto [u, d] = q.top(); q.pop();
    if (st[u]) continue;
    st[u] = true;
    for (auto& [v, w]: son[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        q.push({v, dist[v]});
      }
    }
  }  

  for (int i = 1; i <= n; i ++ ) {
    cout << !(dist[i] - dist[i - 1]) << " \n"[i == n];
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}