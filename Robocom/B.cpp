#include <bits/stdc++.h>
using namespace std;

void solve() {
  int c1, c2, r1, r2; 
  cin >> c1 >> c2 >> r1 >> r2;
  vector<int> n(5); //for(int &x: n) cin >> x;
  for(int i = 1; i <= 4; i ++ ) cin >> n[i]; 

  array<int, 2> st; cin >> st[0] >> st[1];
  int d1, d2; cin >> d1 >> d2;

  vector<vector<int> > g(6, vector<int>(6));
  
  auto chk1 = [&] (int x, int y) {
    int R1 = r1 - n[3];
    int R2 = r2 + n[4];
    if(x == R1 || x == R2) return false;
    if(y == c1 || y == c2) return false;
    return true;
  };

  auto chk2 = [&] (int x, int y) {
    int R1 = r1 - n[3];
    int R2 = r2 + n[4];
    int C1 = c1 + n[1];
    int C2 = c2 - n[2];
    if(x == R1 || x == R2) return false;
    if(y == C1 || y == C2) return false;
    return true;
  };
  
  vector<array<int, 4> > ans;
  for(int i = 1; i <= 5; i ++ ) {
    for(int j = 1; j <= 5; j ++ ) if(chk1(i, j)) {
      
      for(int k = 1; k <= 5; k ++ ) {
        for(int l = 1; l <= 5; l ++ ) {
          if(abs(k - i) + abs(l - j) == d1) {
            if(chk2(k, l)) {
              if(abs(st[0] - k) + abs(st[1] - l) == d2) {
                ans.push_back({i, j, k, l});
              }
            }
          }
        }
      }
    }
  }
  
  sort(ans.begin(), ans.end());
  for(auto& [x, y, z, p] : ans) {
    cout << x << " " << y << " " << z << " " << p << "\n";
  }
}

int main() {
  
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  solve();
  return 0;
}