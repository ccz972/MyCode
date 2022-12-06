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

void solve() {
  int T = 10;
  bool flag = true;
  while(T -- ) {
    system("data.exe > data.txt");
    system("I.exe < data.txt > I.txt");
    system("II.exe < data.txt > II.txt");
    if(system("fc I.txt II.txt")) {
      cout << "error\n";
      flag = false;
      break;
    }
  }

  if(flag) {
    cout << "OK\n";
  } 


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
