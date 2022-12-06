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
  bool flag = true;
  while(T -- ) {
    system("data.exe > data.txt");
    system("Longest_Common_Subsequence.exe< data.txt > A.txt");
    system("baoli.exe < data.txt > B.txt");
    if(system("fc A.txt B.txt")) {
      flag = false;
      cout << "Error\n";
      break;
    }
  }  

  if(flag) {
    cout << "No Error\n";
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
#endif
  return 0;
}
