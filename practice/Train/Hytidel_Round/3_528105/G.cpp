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

bitset<10000010> vis;

void solve() {
  int n; cin >> n;
  vector<array<int, 3> > a(n);
  Rep(i, 0, n) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }
  sort(all(a), [&](auto &x, auto &y) {
    auto [l1, r1, id1] = x;
    auto [l2, r2, id2] = y;
    // if (l1 != l2) return l1 < l2;
    // return r1 < r2;
    if (r1 != r2) return r1 < r2;
    return l1 < l2;
  }); 
  // reverse(all(a));
  int R = a.front()[0];
  vector<int> ans(n);
  Rep(i, 0, n) {
    auto [l, r, id] = a[i];
    rep(j, l, r) if (!vis[j]) {
      ans[id] = j;
      vis[j] = 1;
      break;
    }
    // R = max(R, l);
    // ans[id] = R;
    // ++ R;
  }
  Rep(i, 0, n) {
    cout << ans[i] << " ";
  }
  
  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}