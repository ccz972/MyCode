#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i ++ ) cin >> a[i];
  vector<bool> vis(n);
  vector<int> now(n);
  bool flag = false;
  for(int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    if(a[u] != a[v]) {
      vis[u] = vis[v] = true;
      now[u] ++;
      now[v] ++;
      flag = true;
    }
  }
  
  vector<int> cnt(2, 0); //在旁边有不同颜色的点有多少个

  vector<int> ct(2, 0); //每个点有多少个

  

  for(int i = 0; i < n; i ++ )  {
    if(vis[i]) {
      cnt[a[i]] ++;
    }
    ct[a[i]] ++;
  }

  for(int i = 0; i < n; i ++ ) {
    int ans = ct[a[i]] - 1; //同颜色
    if(now[i]) {
      ans += now[i]; // i 附近不同颜色的，只需要 1 次
      ans += (ct[a[i] ^ 1] - now[i]) * 2; // 不和 i 相邻的 不同颜色的,先到now[i]，再到这个
    } else {
      //i这个点附近没有和他不同颜色的
      // i -> 同颜色-> 相邻不同颜色 -> 这个点  3
      //  i -> 同颜色-> 相邻不同颜色 2
      //i->没有不同颜色的
      if(flag) {
        ans += cnt[a[i] ^ 1] * 2;
        ans += (ct[a[i] ^ 1] - cnt[a[i] ^ 1]) * 3;
      }
    }
    
    cout << ans << " \n"[i == n - 1];

  }







}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}