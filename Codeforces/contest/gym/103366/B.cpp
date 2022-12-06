#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(int i(a); i <= b; ++ i)

void solve() {
  vector<int> a;
  int x, y; cin >> x >> y;
  if(x == 1) {
    cout << "1 0 " << y << "\n"; 
    return ;
  }
  while(x != 1) {
    a.push_back(x / y);
    x %= y;
    swap(x, y);
    // cout << " > " << y << "\n";
  }
  // a.push_back(y);
  cout << (int)a.size() - 1 << " ";
  for(int X: a) cout << X << " ";
  cout << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}