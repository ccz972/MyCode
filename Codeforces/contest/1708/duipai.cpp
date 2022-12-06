#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int T = 100;
  while(T -- ) {
    system("date.exe > data.txt");
    system("C.exe < data.txt C.txt");
    system("tmp.exe < data.txt ac.txt");
    if(system("fc C.txt ac.txt")) {
      cout << "FUCK\n";
      break;
    }
  }

  return 0;
}