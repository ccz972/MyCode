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
  
  /**
   * 题意要求让最后的所有数字相等的最少操作次数
   * 每次操作要么除以2要么除以3，并且满足每次除以都是整除
   * 因此考虑让最后的结果最大，就是他们的gcd
   * 然后暴力判断每个数字的最少操作次数
   * 如果不能通过 /2 /3 得到 gcd 则是不合法，输出 -1
   * 否则最终输出最小操作次数即可.
   * 
  */

  int n; cin >> n;
  vector<int> a(n); int g = 0;
  for (auto& x : a) { cin >> x; g = gcd(g, x); }
  bool flag = true;
  int ans = 0;
  for (int x: a) {
    x /= g;
    while (~x & 1) x >>= 1, ++ ans;
    while (x % 3 == 0) x /= 3, ++ ans;
    if (x != 1) {flag = false; break; }
  }
  if (!flag) return cout << "-1\n", void();
  cout << ans << "\n";
  
  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}