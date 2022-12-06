#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

void solve() {
  int T = 100;
  while (T -- ) {
    system("data.exe > 1.txt");
    system("ach.exe < 1.txt > 2.txt");
    system("HH.exe < 1.txt > 3.txt");
    if (system("fc 2.txt 3.txt")) {
      cout << "FUCK\n";
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}