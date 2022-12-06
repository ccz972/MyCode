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

void solve() {
  string s;
  while (getline(cin, s)) {
    cout << "\"";
    cout << s;
    // for (char c: s) {
    //   if (c == '\\' || c == '\"') cout << "\\";
    //   cout << c;
    // }
    cout << "\",\n";
  }


}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  freopen("1.txt", "w", stdout);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
