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
  int n, m; cin >> n >> m;
  vector<int> a(n); for(int &x: a) cin >> x;
  vector<int> q(n); for(int &x: q) cin >> x;
  vector<long double> p(n); 
  for(int i = 0 ; i < n; i ++ ) {
    p[i] = (long double)q[i] / 10000.0;
  }
  
  auto get1 = [&] () {
    long double ans = 0;
    long double sum = 1;
    for(int i = n - m; i < n; i ++ ) {
      ans += sum * a[i];
      sum *= p[i];
    }
    return ans;
  };

  auto get2 = [&] () {
    long double ans = 0;
    long double sum = 1;
    for(int i = 0; i < m; i ++ ) {
      ans += sum * a[i];
      sum *= p[i];
    }
    return ans;
  };
  
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    return p[j] * a[i] + (long double)(a[i] - a[j]) > p[i] * a[j]; 
  });

  long double ans = max(get1(), get2());

  sort(id.begin(), id.end(), [&](int i, int j) {
    return p[j] * a[i]  > p[i] * a[j]; 
  });

  chkmax(ans, max(get1(), get2()));

  sort(id.begin(), id.end(), [&](int i, int j) {
    return p[j] * a[i]  < p[i] * a[j]; 
  });

  chkmax(ans, max(get1(), get2()));
  srand(unsigned(time(NULL)));
  for(int i = 0; i < 10; i ++ ) {
    random_shuffle(id.begin(), id.end());
    chkmax(ans, max(get1(), get2()));
  }

  cout << fixed << setprecision(10) << ans << "\n";
} 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
