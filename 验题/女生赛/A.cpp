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
  int n, k; cin >> n >> k;
  vector<int> a(n); for (int &x: a) cin >> x;
  if (a[0] == *max_element(all(a))) {
    return cout << "1\n", void();
  }

  // deque<int> dq;
  auto now = 0;;
  vector<int> b;
  int win = 0;
  for (int i = 1; i < n; i ++ ) {
    if (a[now] >= a[i]) {
      b.push_back(i);
      ++ win;
      if (win == k) {
        cout << now + 1 << "\n";
        return ;
      }
    } else {
      win = 1;
      b.push_back(now);
      now = i;
    }
  }

  cout << now + 1 << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}