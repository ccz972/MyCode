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
constexpr int N = 2e5 + 10;
int fa[N], d[N];
bool vis[N];
int now[N];
array<int, 2> limit[N];
vector<int> son[N];
ll ans;
ll f[N];
void init(int n) {
  rep(i, 1, n) {
    fa[i] = d[i] = now[i] = 0;
    vis[i] = false;
    limit[i][0] = limit[i][1] = 0;
    son[i].clear();
    f[i] = 0;
  }
  ans = 0;
}

void dfs(int u) {
  //f[i] 表示 i 最大选多少
  for(int v: son[u]) {
    dfs(v);
    f[u] += f[v];
  }
  if(son[u].empty()) {
    ans ++; //一个叶子必须有一次
    f[u] = limit[u][1]; //如果为叶子节点，就是 f[i] = r[i]
  } else {
    if(f[u] < limit[u][0]) { //如果 f[i] < l[i] 说明要多一次
      ans ++;
      f[u] = limit[u][1]; //这次肯定这个点往大了选
    } else {
      f[u] = min(f[u], (ll)limit[u][1]); //记得要取一个min ！！！
    }
  }
}

void solve() {
  int n; cin >> n;
  rep(i, 2, n) {
    cin >> fa[i];
    son[fa[i]].push_back(i);
  }
  rep(i, 1, n) {
    cin >> limit[i][0] >> limit[i][1];
  }
  dfs(1);
  cout << ans << "\n";
  init(n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}