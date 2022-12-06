#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

bool chk(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int cnt = 0;
  for(int i = l; i <= r; i ++ ) {
    int x; cin >> x;
    if(x < l || x > r) cnt ++;
  }
  if(((r - l + 1) & 1) == (cnt & 1)) return false;
  return true;
}

void solve() {
  cin >> n;
  int l = 1, r = n;
  while(l < r) {
    int mid = (l + r) / 2;
    if(chk(l, mid)) r = mid;
    else l = mid + 1;
  }
  cout << "! " << l << endl;
}

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}