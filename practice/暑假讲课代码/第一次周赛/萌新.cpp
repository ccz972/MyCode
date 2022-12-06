#include <bits/stdc++.h>
using namespace std;

int n, m;
int Case;

void solve() {
  vector<int> a(m);
  for(int i = 0; i < m; i ++ ) {
    cin >> a[i];
  }
  int now = 0, ans = 0;
  sort(a.begin(), a.end());
  for(int i = n * m; i >= 1; i -- ) {
    if(i == a.back()) {
      if(!now) {
        ans ++;
      } else {
        -- now;
      }
      a.pop_back();
    } else {
      now ++;
    }
  }
  cout << "Case " << ++ Case << ": " << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(cin >> n >> m, n || m) {
    solve();
  }

  return 0;
}