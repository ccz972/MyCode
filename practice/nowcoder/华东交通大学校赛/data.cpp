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
  int n = rnd(4) + 1, m;
  cout << n << "\n";
  vector<int> fa(n + 1);
  for (int i = 2; i <= n; i ++ ) {
    fa[i] = rnd(i - 1) + 1;
  }
  for (int i = 2; i <= n; i ++ ) {
    cout << fa[i] << " " << i << " " << rnd(5) + 1 << "\n";
  }
  m = rnd(5) + 1;
  set<int> s;
  for (int i = 1; i <= m; i ++ ) {
    s.insert(rnd(n) + 1);
  }  
  cout << SZ(s) << " "; for (int x: s) cout << x << " ";
  cout << "\n";
  m = rnd(5) + 1;
  s.clear();
  for (int i = 1; i <= m; i ++ ) {
    s.insert(rnd(n) + 1);
  }  
  cout << SZ(s) << " "; for (int x: s) cout << x << " ";
  cout << "\n";
  m = rnd(5) + 1;
  s.clear();
  for (int i = 1; i <= m; i ++ ) {
    s.insert(rnd(n) + 1);
  }  
  cout << SZ(s) << " "; for (int x: s) cout << x << " ";
  cout << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}