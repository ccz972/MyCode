#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    lg.resize(n + 1); lg[1] = 0; 
    for (int i = 2; i <= n; i ++ ) lg[i] = lg[i >> 1] + 1;
    int m = lg[n] + 1;
    maxv.resize(m); 
    for (int i = 0; i < m; i ++ ) maxv[i].resize(n);
    for (int i = 0; i < n; i ++ ) maxv[0][i] = a[i];

    for (int i = 1; i < m; i ++ ) {
      for (int j = 0; j <= n - (1 << i); j ++ ) {
        maxv[i][j] = gcd(maxv[i - 1][j], maxv[i - 1][j + (1 << (i - 1))]);
      }
    }

  }
  T getgcd(int l,int r){
    int k = lg[r - l + 1];
    return gcd(maxv[k][l], maxv[k][r - (1 << k) + 1]);
  }    
private:
  int n;
  vector<T> a;
  vector<int> lg;
  vector<vector<T>> maxv;
};
void solve() {
  int n; cin >> n;
  vector<int> a(n); for (int &x: a) cin >> x;
  int cntz = count(a.begin(), a.end(), 1);
  if (cntz) {
    cout << n - cntz << "\n";
    return;
  }
  for (int i = 0; i < n - 1; i ++ ) {
    if (gcd(a[i], a[i + 1]) == 1) {
      cout << n << "\n";
      return ;
    }
  }
  ST st(a, n);
  if (st.getgcd(0, n - 1) != 1) {
    cout << "-1\n";
    return ;
  }
  int ans = n;
  for (int i = 0; i < n - 1; i ++ ) if (st.getgcd(i, n - 1) == 1) {
    int l = i + 1, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (st.getgcd(i, mid) != 1) l = mid + 1;
      else r = mid;
    }
    //1 2 3
    chkmin(ans, l - i);
  }

  ans += n - 1;

  cout << ans << "\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
