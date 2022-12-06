#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

void solve() {
  int n; cin >> n;
  vector<int> s(n), c(n);
  for (int &x: s) cin >> x;
  for (int &x: c) cin >> x;
  auto alls = s;
  sort(all(alls));
  alls.erase(unique(all(alls)), alls.end());
  auto find = [&] (int x) {
    return lower_bound(all(alls), x) - alls.begin() + 1;
  };
  int m = alls.size();
  vector<array<int, 2> > dp(m + 1, {INF, INF});
  int ans = INT_MAX;
  for (int i = 0; i < n; i ++ ) {
    int x = find(s[i]);
    chkmin(dp[x][0], c[i]);
    for (int j = 1; j < x; j ++ ) {
      chkmin(dp[x][1], dp[j][0] + c[i]);
      chkmin(ans, dp[j][1] + c[i]);
    }
  }  
  if (ans > INF) ans = -1;
  cout << ans << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}