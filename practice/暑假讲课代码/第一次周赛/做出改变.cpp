#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

const int N = 1e5 + 10;
int Case;
int n, a[N];

bool chk(int x) {
  int now = a[1] - x;
  for(int i = 2; i <= n; i ++ ) {
    if(a[i] > now) {
      now = max(now + 1, a[i] - x);
    } else {
      if(now >= a[i] + x) return false;
      now ++;
    }
  }
  return true;
}

void solve() {

  cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }  

  int l = 0, r = 1e7;

  while(l < r) {
    int mid = (l + r) / 2;
    if(chk(mid)) r = mid;
    else l = mid + 1;
  }

  cout << "Case #" << ++ Case << ":\n";
  cout << l << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}