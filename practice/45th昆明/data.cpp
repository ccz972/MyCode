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
  // cout << "1\n";
  int n = 100000;
  cout << n << "\n";
  for (int i = 2; i <= n; i ++ ) cout << i << " ";
  cout << "1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- ) solve();

  return 0;
}