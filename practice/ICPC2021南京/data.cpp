#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

void solve() {
  int T = rnd(10) + 1; T = 1;
  cout << T << "\n";
  while (T -- ) {
    int n = rnd(10000) + 1;
    cout << n << "\n";
    rep(i, 1, n) {
      cout << rnd(20000000) + 1 << " \n"[i == n];
    }
    rep(i, 1, n) {
      cout << rnd(3) + 1 << " \n"[i == n];
    }
    vector<int> fa(n + 1);
    rep(i, 2, n) {
      fa[i] = rnd(i - 1) + 1;
    }
    rep(i, 2, n) {
      cout << i << " " << fa[i] << "\n";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}