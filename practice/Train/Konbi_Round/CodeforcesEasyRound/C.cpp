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
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  ll sum = accumulate(all(a), 0ll);
  
  if (sum == 0ll) {
    cout << "Possible\n";
    Rep(i, 0, n) cout << "1 "; 
    return ;
  }

  if (count(all(a), 0) != 0) return cout << "Impossible\n", void();

  vector<int> b(n);

  map<int, int> mp;

  for (int i = 0; i < n; i ++ ) {
    b[i] = n - a[i];
    mp[b[i]] ++;
  }

  //有a[i]个和它不一样，那么i有 n-a[i]个 
  //3 3
  //1 2 3 3
  //3 3 2 2
  sum = 0;
  for (auto [k, v]: mp) {
    if (v % k) return cout << "Impossible\n", void();
    sum += v;
  }

  if (sum != (ll)n) return cout << "Impossible\n", void();

  cout << "Possible\n";

  map<int, int> ans;
  int now = 0;
  //2 
  //2 2 2 2 

  for (int i = 0; i < n; i ++ ) {
    if (mp[b[i]] % b[i] == 0) {
      ans[b[i]] = ++ now;
    } 
    mp[b[i]] --; 
    cout << ans[b[i]] << " ";
  }
  

  /**
   * 第i个人有a[i]个人和他不一样，说明  cnt[ b[i] ] + a[i] = n ? 
   * 说明什么？ 
   * 说明所有的不同的a_i相加一定是小于等于n的 
  */

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}