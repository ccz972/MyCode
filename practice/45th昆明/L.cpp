#include <bits/stdc++.h>
using namespace std;
#define SZ(s) ((int)s.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define PII pair<int, int>

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

constexpr int N = 1E6 + 10;

int n, a[N], stk[N], ans[N], idx[N]; 
int col;
void solve() {
  cin >> n; col = 0;
  rep(i, 1, n) cin >> a[i]; //, idx[a[i]] = i;
  reverse(a + 1, a + 1 + n);
  rep(i, 1, n) idx[a[i]] = i;
  int m = 0; 
  rep(i, 1, n) {
    int tt = lower_bound(stk + 1, stk + 1 + m, a[i]) - stk;
    // cout << "flag = " << tt << " " << stk[tt] << " " << m << "\n";
    if (tt > m) {
      ans[i] = ++ col;
      m = tt;
      stk[tt] = a[i];
    } else {
      ans[i] = ans[idx[stk[tt]]];
      stk[tt] = a[i];
    }
  }
  reverse(ans + 1, ans + 1 + n);
  int mx = *max_element(ans + 1, ans + 1 + n);
  cout << mx << "\n";
  rep(i, 1, n) {
    cout << ans[i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- ) solve();

  return 0;
}