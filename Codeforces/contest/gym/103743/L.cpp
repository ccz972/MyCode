#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  // vector<bool> vis(n);
  vector<int> R(n);
  for(int i = 1; i < n; i ++ ) if(s[i] == 'B') {
    int l = i, r = i;
    while(l - 1 >= 0 && r + 1 < n && s[l - 1] == 'A' && s[r + 1] == 'C') {
      -- l, ++ r;
      // vis[l] = vis[r] = true;
    }
    // if(l == i) continue;
    // vis[i] = true;
    R[i] = i - l;
  }
  int ans = 0;
  
  // int idx = -1;
  
  for(int i = 2; i <= n; i += 2 ) if(s[i - 1] == 'B' && R[i - 1]) {
    ans ++;
    R[i - 2] = R[i - 1] - 1;
    R[i - 1] = 0;
  }
  
  int cnt = 0;
  for(int i = 1; i <= n; i ++ ) if(R[i - 1]) {
    ans += min(cnt + 1, R[i - 1]);

    cnt ++;
  }

  cout << ans << "\n";
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}