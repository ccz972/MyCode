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

  int T = 100;
  while(T -- ) {
    system("data.exe > 1.txt");
    system("tmp.exe < 1.txt > 2.txt");
    system("ac.exe < 1.txt > 3.txt");
    if(system("fc 2.txt 3.txt")) {
      cout << "FUCK";
      break;
    }
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
