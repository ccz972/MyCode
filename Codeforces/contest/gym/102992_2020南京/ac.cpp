#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 

void get(int &x, int &y, char c) {
  if (c == 'U') y ++;
  if (c == 'D') y --;
  if (c == 'L') x --;
  if (c == 'R') x ++;
}

void solve() {
  int x, y, ax, ay; cin >> ax >> ay;
  string s; cin >> s;
  x = 0, y = 0;
  for (char c: s) get(x, y, c);
  if (x == ax && y == ay) {
    cout << "FUCK\n";
  } else {
    cout << "accept\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}