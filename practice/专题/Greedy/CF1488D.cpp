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
constexpr ll INFF = 0x3f3f3f3f3f3f3f3f;
// constexpr int N = 2E5 + 10;

void solve() {
  ll n, s; cin >> n >> s;

  auto chk = [&] (ll x) -> bool {
    if (x < s / n) return false;
    ll sum = 0, cnt = n;
    while (x != 1 && cnt) {
      sum += x;
      cnt --;
      x = (x + 1) / 2;
    }//15
    sum += cnt;
    return sum <= s;
  };
  if (chk(16)) cout << "FUCK\n";
  ll l = 1, r = s;

  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (chk(mid)) l = mid;
    else r = mid - 1; 
  }
  cout << l << "\n";


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}