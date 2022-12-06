#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n; ll H; cin >> n >> H;
  vector<vector<ll> > a(n);
  vector<int> t(n);

  ll sum = 0;
  for(int i = 0; i < n; i ++ ) {
    cin >> t[i];
    int len; cin >> len;
    a[i].resize(len + 1);
    for(int j = 1; j <= len; j ++ ) {
      cin >> a[i][j];
      sum += a[i][j];
      a[i][j] += a[i][j - 1];
    }
  }

  if(sum < H) {
    cout << "-1\n";
    return;
  }

  auto check = [&] (int x) -> bool {
    vector<ll> f(1 << n);
    for(int i = 0; i < 1 << n; i ++ ) {
      int cnt = 0; 
      for(int j = 0; j < n; j ++ ) if(i >> j & 1) {
        cnt += t[j];
      }
      if(cnt > x) continue;
      for(int j = 0; j < n; j ++ ) if(not(i >> j & 1)) {
        ll ret = f[i];
        if(x - cnt + 1 >= (int)a[j].size() - 1) {
          ret += a[j].back();
        } else {
          ret += a[j][x - cnt + 1];
        } 
        if(ret >= H) return true;
        chkmax(f[i ^ (1 << j)], ret);
      }
    }
    return *max_element(f.begin(), f.end()) >= H;
  };

  int l = 0, r = 1800001;

  while(l < r) {
    int mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l << "\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while(T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}

/*


a[0][i][j] 代表第i位初始值为0执行到第j次操作的值
a[1][i][j] 代表第i位初始值为1执行到第j次操作的值


*/