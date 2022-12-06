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
  string s1, s2; cin >> s1 >> s2;
  reverse(all(s1));
  while (SZ(s1) > 1 && s1.back() == '0') s1.pop_back();
  reverse(all(s1));
  reverse(all(s2));
  while (SZ(s2) > 1 && s2.back() == '0') s2.pop_back();
  reverse(all(s2));
  if (s2 == "0") {
    cout << "PLMM";
  } else if (s2[0] < '5') {
    cout << "Happy birthday to YXGG";
  } else if (s2 == "5") {
    if ((s1.back() - '0') & 1) {
      cout << "Happy birthday to MFGG";
    } else {
      cout << "Happy birthday to YXGG";
    }
  } else {
    cout << "Happy birthday to MFGG";
  }
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}