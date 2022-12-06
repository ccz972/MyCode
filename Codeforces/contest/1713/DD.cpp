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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int query(int l, int r) { 
  cout << "? " << l << " " << r << endl;
  int x; cin >> x;
  return x;
}

int get1(int idx, vector<int> &a) {
  int res1 = query(a[idx * 4], a[idx * 4 + 2]);
  int res2 = query(a[idx * 4 + 1], a[idx * 4 + 3]);
  if(!res1) {
    return res2 == 1 ? a[idx * 4 + 1] : a[idx * 4 + 3];
  } else if(!res2) {
    return res1 == 1 ? a[idx * 4] : a[idx * 4 + 2];
  } else {
    int l = res1 == 1 ? a[idx * 4] : a[idx * 4 + 2];
    int r = res2 == 1 ? a[idx * 4 + 1] : a[idx * 4 + 3];
    int res = query(l, r);
    return res == 1 ? l : r; 
  }
}

int get2(int idx, vector<int> &a) {
  int res1 = query(a[idx * 4], a[idx * 4 + 3]);
  int res2 = query(a[idx * 4 + 1], a[idx * 4 + 2]);
  if(!res1) {
    return res2 == 1 ? a[idx * 4 + 1] : a[idx * 4 + 2];
  } else if(!res2) {
    return res1 == 1 ? a[idx * 4] : a[idx * 4 + 3];
  } else {
    int l = res1 == 1 ? a[idx * 4] : a[idx * 4 + 3];
    int r = res2 == 1 ? a[idx * 4 + 1] : a[idx * 4 + 2];
    int res = query(l, r);
    return res == 1 ? l : r; 
  }
}

void solve() {
  int n; cin >> n; n = 1 << n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  int m = n;
  while(m >= 4) {
    m /= 4;
    vector<int> b(m);
    for(int i = 0; i < m; i ++ ) {
      int p = rng() % INT_MAX;
      if(p & 1) {
        b[i] = get1(i, a);
      } else {
        b[i] = get2(i, a);
      }
    }
    a.swap(b);
  }
  if(a.size() == 1) {
    cout << "! " << a[0] << endl;
  } else { 
    int res = query(a[0], a[1]);
    int ans = res == 1 ? a[0] : a[1];
    cout << "! " << ans << endl;
  }
}

int main() {
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}