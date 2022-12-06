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

vector<int> v;
map<ll, int> p;

ll dfs(int a, int c) {
  if (a == 1ll) return 0ll;
  if (c == 1ll) return a - 1;
  if (p.count(a * 1E9 + c)) return p[a * 1E9 + c]; 
  ll minn = a - 1;
  for (auto x: v) if (c % x == 0) {
    int res = a % x;
    chkmin(minn, min(res + 1 + dfs(a / x, c / x), x - res + 1 + dfs(a / x + 1, c / x)));
  }
  return p[a * 1E9 + c] = minn;
}

void solve() {
  ll a, b; cin >> a >> b;
  if (a > b) swap(a, b);
  ll c = b - a;
  for (ll i = 2; i <= c / i; i ++ ) if (c % i == 0) {

  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- )
  solve();
  return 0;
}