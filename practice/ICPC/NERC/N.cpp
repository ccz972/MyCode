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
  string s; cin >> s;
  int n; cin >> n;
  string t; t.push_back(s[0]);
  auto m = n;
  for (int i = 1; i < SZ(s); i ++ ) {
    if (s[i] == '0') {
      while (SZ(t) > 1 && n && t.back() > s[i]) {
        t.pop_back();
        -- n;
      } 
    } else {
      while (!t.empty() && n && t.back() > s[i]) {
        t.pop_back();
        -- n;
      }
    }
    if (s[i] == '0') {
      t += s[i];
    } else if (!n) {
      t += s.substr(i, SZ(s));
      break;
    } else {
      if (t.empty()) {
        t += s[i];
      } else {
        if (t.back() == '0') {
          if (t[0] > s[i]) {
            if (n >= SZ(t)) {
              n -= SZ(t);
              t.clear();
              t += s[i];
            } else {
              t += s[i];
            }
          } else {
            t += s[i];
          }
        } else {
          t += s[i];
        }
      }
    }
    // cout << t << " " << n << "\n";
  }
  while (n) {
    t.pop_back();
    -- n;
  }
  // cout << SZ(t) << " " << m << " " << SZ(s) << "\n";
  assert(SZ(t) + m == SZ(s));
  cout << t << "\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}