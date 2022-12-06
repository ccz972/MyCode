#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
// mt19937 rnd(random_device{}()); 
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n; cin >> n;
  string s; cin >> s; // int n = s.size();
  // cout << n << "\n" << s << "\n";
  bitset<1000010> bit(s);
  string ss(bit.to_string());
  for (int i = 1; i < 500; i ++ ) {
    chkmax(ss, (bit | (bit >> i)).to_string());
  }
  reverse(ss.begin(), ss.end());
  while (ss.size() > 1 && ss.back() == '0') ss.pop_back();
  // debug(ss.size());
  reverse(ss.begin(), ss.end());
  cout << ss << "\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
