#include <bits/stdc++.h>
using namespace std;
#define SZ(s) ((int)s.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define PII pair<int, int>

void solve() {
  int T = 100;
  while (T -- ) {
    system("J.exe > 1.txt");
    system("check.exe < 1.txt > 3.txt");
    // system("ac.exe < 1.txt > 2.txt");
    // system("J.exe < 1.txt > 3.txt");
    if (system("fc ac.txt 3.txt"))  {
      cout << "FUCK\n"; break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- ) solve();

  return 0;
}