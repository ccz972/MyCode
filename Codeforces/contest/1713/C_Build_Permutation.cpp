#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int get(int x) {
  int l = 0, r = 10000;
  while(l < r) {
    int mid = l + r >> 1;
    if(mid * mid < x) l = mid + 1;
    else r = mid;
  }  
  return l;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  
  int idx = n - 1;
  int m = n - 1;
  while(idx > 0) {
    int x = get(m);//当前没填的最大值 (
    int p = x * x - m; //末尾要填的值
    int tmp = p;
    while(p <= m) {
      a[idx] = p;
      idx --;
      p ++;
    }
    m = tmp - 1;
  }


  
  for(int x: a) cout << x << " ";
  cout << "\n";
  //idx
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}