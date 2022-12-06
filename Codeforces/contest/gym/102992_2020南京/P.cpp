#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

int a[10000][10000];

void solve() {
  int n = 4;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= n; j ++ ) {
      a[i][j] = rnd(3);
    }
  }
  for (int i = 1; i <= n; i ++ ) {
    rep(j, 1, n) cin >> a[i][j];
  }
  bool flag = true;
  rep(i, 1, n) {
    rep(j, 1, n) {
      rep(k, i + 1, n) {
        rep(l, j + 1, n) {
          if ((a[i][j] == a[i][l] && a[k][j] == a[k][l]) || (a[i][j] == a[k][j] && a[i][l] == a[k][l])) {
            flag = false;
            cout << i << " " << j << " " << k << " " << l << "\n";
            goto ed;
          }
        }
      }
    }
  }
  ed:
  if (flag) {
    cout << "FUCK\n";
    rep(i, 1, n) {
      rep(j, 1, n) {
        cout << a[i][j] << " \n"[j == n];
      }
    }
  } else {
    cout << "accept\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}