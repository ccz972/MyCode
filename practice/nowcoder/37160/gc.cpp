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
  int T = 10000;
  bool f = 0;
  while(T -- ) {
    system("data.exe > data.txt");
    system("I.exe < data.txt > I.txt");
    system("ans.exe < data.txt > ans.txt");
    if(system("fc I.txt ans.txt")) {
      f = 1;
      break;
    }
  }

  if(f) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }

  return 0;
}