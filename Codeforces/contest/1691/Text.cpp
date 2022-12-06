#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}

void solve() {
  int n = 32;
  map<int, vector<int> > mp, teshu;
  while(n -- ) {
    vector<int> s; int x = n;
    //15 7 3 1  1
    bitset<5> b(x);
    cout << b << " "; int point = 0;
    for(int i = 3; i >= 0; i -- ) {
      point += b[i + 1] * 10 + b[i];
    }
    cout << point << "\n";
    if(b[4] && b[0])
      teshu[b.count()].push_back(point);
    mp[b.count()].push_back(point);
  }
  for(auto [k, v] : mp) {
    cout << k << " : ";
    
    for(int x: v) {
      // if(x >> 4 & 1 && x & 1)
      //   cout << "\"" << x  << "\"" << " ";
      // else 
      cout << x << " ";
    }
    cout << "\n";
  }

  for(auto [k, v] : teshu) {
    cout << k << " : ";
    
    for(int x: v) {
      // if(x >> 4 & 1 && x & 1)
      //   cout << "\"" << x  << "\"" << " ";
      // else 
      cout << x << " ";
    }
    cout << "\n";
  }

}