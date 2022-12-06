#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define int long long

double pow(double x, int p) {
  double ans = 1;
  while (p) {
    if (p & 1) ans *= x;
    p >>= 1;
    x = x * x;
  }
  return ans;
}

double n, m, p; 
double fuc (int len) {
  return (n * len + m) / (1 - pow(1 - p, len));  
}

void solve() {
  cin >> n >> m >> p;
  p *= 1e-4;

  int l = 1, r = 100000;
  for (int i = 0; i < 30; i ++ ) {
    int ml = (l + r) / 3;
    int mr = (l + r) / 3 * 2;
    double tl = fuc(ml), tr = fuc(mr);
  
    // cout << l << ' ' << r << endl;

    if(tl <= tr){
      r = mr;
    } else {
      l = ml;
    }
  }

  double ans = 5e18;

  for(int i = l; i <= r; i ++){
    ans = min(ans, fuc(i));
  }
  cout << fixed << setprecision(10);
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T -- )
  solve();
  return 0;
}