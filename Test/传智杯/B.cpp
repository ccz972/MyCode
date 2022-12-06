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
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &x: a) cin >> x;
  for (int &x: b) cin >> x;
  reverse(all(a)); reverse(all(b));
  vector<int> c(max(n, m) + 100);
  while (SZ(a) < SZ(c)) a.push_back(0);
  while (SZ(b) < SZ(c)) b.push_back(0);
  int p = SZ(c);
  Rep(i, 0, p) {
    int base = i + 2;
    c[i] += a[i] + b[i];
    int ca = c[i] / base;
    c[i] %= base;
    if (i + 1 < p) {
      c[i + 1] += ca;
      ca = 0;
    }
  }
  bool flag = false;
  vector<int> ans;
  reverse(all(c));
  for (int i = 0; i < p; i ++ ) {
    if (c[i]) {
      flag = true;
    }
    if (flag) {
      ans.push_back(c[i]);
    }
  }
  if (SZ(ans) == 0) cout << "0";
  else {
    for (int x: ans) cout << x << " ";
  }

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}