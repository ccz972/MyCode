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

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

bool isConvex(vector<vector<int>>& points) {
  int n = points.size();
  int xa, ya, xb, yb, xc, yc;
  int prevsign = 0;
  for(int i=0; i<n; i++) {
    xa = points[i][0];
    ya = points[i][1];
    xb = points[(i + 1) % n][0];
    yb = points[(i + 1) % n][1];
    xc = points[(i + 2) % n][0];
    yc = points[(i + 2) % n][1];
    int cur = (xc-xb) * (yb-ya) - (yc-yb) * (xb-xa);
    if(prevsign == 0){
      prevsign = cur;
    } else {
      if(prevsign < 0 && cur > 0) return false;
      if(prevsign > 0 && cur < 0) return false;
    }
  }
  return true;
}

void solve() {
  vector<vector<int> > a(4);
  for (int i = 0; i < 4; i ++ ) {
    int x, y; cin >> x >> y;
    a[i].push_back(x);
    a[i].push_back(y);
    // cin >> a[i][0] >> a[i][1];
  }

  bool flag = isConvex(a);
 
  if (flag) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  // double z1 = (x2-x1)*(y)


}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}