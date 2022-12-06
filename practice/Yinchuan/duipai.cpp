#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define rep(i, a, b) for (int i(a); i <= (b); i ++ )
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define all(a) a.begin(), a.end()

void solve() {
  int T = 100;
  while (T -- ) {
    system("data.exe > 1.txt");
    system("ac.exe < 1.txt > 2.txt");
    system("F.exe < 1.txt > 3.txt");
    if (system("fc 2.txt 3.txt")) {
      cout << "FCUCK\n";
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}