#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(x, y) (x) = (x) >= (y) ? (x) : (y)
#define chkmin(x, y) (x) = (x) <= (y) ? (x) : (y)
#define PII pair<int, int>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define debug(x) cout << #x << " : " << x << "\n"
mt19937 rng(random_device{}());
int rnd(int x) {
	return rng() % x;
}
void solve() {
	int T = 1; cout << T << "\n";
  int n = rnd(100) + 1, m = rnd(n) + 1;
  cout << n << " " << m << "\n";
  for (int i = 1; i <= n; i ++ ) {
    cout << rnd(1000100) + 1 << " ";
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