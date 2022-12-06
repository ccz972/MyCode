#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int T = 9;
  cout << T * 10000 << "\n";
  while(T -- ) {
    string s[3];
    for(int i = 0; i < 3; i ++ ) {
      getline(cin, s[i]);
    }
    for(int i = 0; i < 10000; i ++ ) {
      for(int j = 0; j < 3; j ++ ) {
        cout << s[j] << "\n";
      }
    }
  }  


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("B.txt", "r", stdin);
  freopen("data.txt", "w", stdout);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
