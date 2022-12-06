#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, q; cin >> n >> k >> q;
  vector<int> a(k + 1);
  vector<bool> vis(n + 100, false);

  for(int i = 1; i <= k; i ++ ) {
    cin >> a[i];
    vis[a[i]] = true;
  }

  vector<int> l(q + 1);
  for(int i = 1; i <= q; i ++ ) {
    cin >> l[i];
  }

  for(int i = 1; i <= q; i ++ ) {
    int now = l[i];
    // cout << "> " << a[now] + 1 << " " << (int)vis[a[now] + 1] << "\n";
    if(a[now] != n && !vis[a[now] + 1]) {
      vis[a[now]] = false;
      a[now] ++;
      vis[a[now]] = true;
    }
    // cout << now << " " <<  a[now] << "\n";
    // }
  }
  // for(int i = 1; i <= q; i ++ ) {
  //   if(a[l[i]] == n) continue;
  //   if(!vis[a[l[i]] + 1]) {
  //     // cout << vis[a[l[i]]] << "\n";
  //     vis[a[l[i]]] = false;
  //     a[l[i]] ++;
  //     vis[a[l[i]]] = true;
  //   }
  // }

  for(int i = 1; i <= n; i ++ ) if(vis[i]) {
    cout << i << " ";
  }

}