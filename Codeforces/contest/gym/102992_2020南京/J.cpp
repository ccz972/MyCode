#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 


void solve() {
  int n, k; cin >> n >> k;
  if (!k) {
    cout << "-1\n";
  } else if (k == 1) {
    rep(i, 1, n) cout << i << " ";
  } else {
    rep(i, 2, k) {
      cout << i << " ";
    }
    cout << "1 ";
    rep(i, k + 1, n) cout << i << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}