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
    int m = __lg(n) + 1;
    maxv.resize(m); minv.resize(m);
    
    for (int i = 0; i < m; i ++ ) maxv[i].resize(n), minv[i].resize(n); 
    for (int i = 0; i < n; i ++ ) maxv[0][i] = minv[0][i] = a[i];

    for (int i = 1; i < m; i ++ ) {
      for (int j = 0; j <= n - (1 << i); j ++ ) {
        maxv[i][j] = max(maxv[i - 1][j], maxv[i - 1][j + (1 << (i - 1))]);
        minv[i][j] = min(minv[i - 1][j], minv[i - 1][j + (1 << (i - 1))]);
      }
    }

  }
  T getmax(int l,int r){
    int k = __lg(r - l + 1);
    return max(maxv[k][l], maxv[k][r - (1 << k) + 1]);
  }    
  T getmin(int l,int r){
    int k = __lg(r - l + 1);
    return min(minv[k][l], minv[k][r - (1 << k) + 1]);
  }    
private:
  int n;
  vector<T> a;
  vector<vector<T>> maxv, minv;
};

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n); for (int &x: a) cin >> x; ST st(a, n);
  vector<long long> s(n); s[0] = a[0];
  for (int i = 1; i < n; i ++ ) s[i] = s[i - 1] + a[i];

  vector<array<int, 3> > b(q);
  for (auto& [l, r, id]: b) cin >> l >> r >> id;
  sort(b.begin(), b.end());

  vector<long long> ans(n);
  vector<int> 

  for (int i = 0; i < n; i ++ ) {

  }
  


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
