
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 


void solve() {
  int T = 10000;
  while (T -- ) {
    system("P.exe > 1.txt");
    if (system("fc 1.txt ac.txt")) {
      cout << "FUCK\n";
      break;
    }
    // system("L.exe < 1.txt > 3.txt");
    // if (system("fc 2.txt 3.txt")) {
    //   cout << "FUCK\n";
    //   break;
    // }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}