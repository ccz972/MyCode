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
  vector<int> a(n + 1), pos(n + 1); rep(i, 1, n ) cin >> a[i], pos[a[i]] = i;
  vector<bool> win(n + 1);
  for (int i = n; i >= 1; i -- ) {
    bool ok = false;
    for (int j = i; j + pos[i] <= n && !ok; j += i ) {
      if (a[pos[i] + j] < i) continue;
      if (!win[j + pos[i]]) {
        ok = true; break;
      }
    }
    for (int j = i; pos[i] - j >= 1 && !ok; j += i ) {
      if (a[pos[i] - j] < i) continue;
      if (!win[pos[i] - j]) {
        ok = true; break;
      }
    }
    if (ok) win[pos[i]] = true;
  }

  rep(i, 1, n) {
    cout << (win[i] ? "A" : "B"); 
  }

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}