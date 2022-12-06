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

void solve() {
  // string p = "LRUD";
  // int n = rnd(12) + 1;
  int T = 1; cout << T << "\n";
  int x = rnd(20), y = rnd(20);
  cout << x << " " << y << "\n";
  int n = rnd(10000) + 1;
  // int l = rnd(2), r = rnd(2) + 2;
  int l = 1, r = 2;
  string t = "LRUD";
  int cntl = rnd(10), cntr = rnd(10);
  rep(i, 1, cntl) cout << t[l];
  rep(i, 1, cntr) cout << t[r];

}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // int T = 20; 
  // while (T -- )
  solve();
  return 0;
}