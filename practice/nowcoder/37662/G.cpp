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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int x, y; cin >> x >> y;
  x --;
  // if(y <= n) {
  //   while(y -- ) {
  //     x = (x + a[x]) % n;
  //   }
    
  //   cout << x << "\n";

  //   return 0;
  // }

  vector<int> t(n, -1);
  vector<int> k;
  int t1, t2;
  while(true) {
    if(t[x] != -1) {
      t1 = t[x];
      t2 = k.size();
      t2 -= t1;
      //0 1 2 3 4 5 2
      //    2     5
      break;
    } else {
      t[x] = k.size();
      k.push_back(x);
      x = (x + a[x]) % n;
    }
  }
  //0 1 3 0
  // [t1, t2]
  // 0 1  2 3 4 5 2
  // 
  // for(auto p: k) {
  //   cout << p << " ";
  // }

  // cout << "\n";
  // cout << t1 << " " << t2 << " >>>\n";
  if(y < t1) { 
    cout << k[y] + 1;
  } else {
    //0 1 2
    cout << k[(y - t1) % t2] + 1;
    // if((y - t1) % t2 == 0) {
    //   cout << k.back() + 1;
    // } else {
    //   cout << k[(y - t1) % t2 + t1] + 1;
    // }
  }

  // if((y - t1))
  

  return 0;
}