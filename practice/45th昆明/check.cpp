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

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1); rep(i, 1, n) cin >> a[i];
  int op; cin >> op;
  while (op -- ) {
    int m; cin >> m;
    for (int i = 0; i < m; i ++ ) {
      int u, v; cin >> u >> v;
      swap(a[u], a[v]);
    } 
  }
  if (is_sorted(a.begin() + 1, a.end())) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while (T -- ) solve();

  return 0;
}