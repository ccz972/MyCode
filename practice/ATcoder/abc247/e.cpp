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
//使用的时候注意判断如果 多个最值 取左边下标还是右边下标
//分别对应 >= >   <= <
template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    lg.resize(n + 1); lg[1] = 0; 
    for (int i = 2; i <= n; i ++ ) lg[i] = lg[i >> 1] + 1;
    int m = lg[n] + 1;
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
    int k = lg[r - l + 1];
    return max(maxv[k][l], maxv[k][r - (1 << k) + 1]);
  }    
  T getmin(int l,int r){
    int k = lg[r - l + 1];
    return min(minv[k][l], minv[k][r - (1 << k) + 1]);
  }    
private:
  int n;
  vector<T> a;
  vector<int> lg;
  vector<vector<T>> maxv, minv;
};


void solve() {
  int n, l, r; cin >> n >> r >> l;
  // swap(l, r);
  vector<int> a(n); for (int &x: a) cin >> x;
  ST st(a, n);
  ll ans = 0;
  for (int i = 0; i < n; i ++ ) if (a[i] >= l && a[i] <= r) {
    int L = i, R = n - 1;
    while (L < R) {
      int MID = (L + R + 1) / 2;
      if (st.getmax(i, MID) > r) R = MID - 1;
      else L = MID;
    }
    //此时的L就是最大值的右边界
    if (st.getmax(i, L) != r) continue;
    int maxr = L;
    L = i, R = R;
    while (L < R) {
      int MID = (L + R) / 2;
      if (st.getmax(i, MID) >= r) R = MID;
      else L = MID + 1;
    }
    int maxl = L;
    if (st.getmax(i, L) != r) continue;
    if (maxl > maxr) continue;

    L = i, R = n - 1;
    while (L < R) {
      int MID = (L + R + 1) / 2;
      if (st.getmin(i, MID) < l) R = MID - 1;
      else L = MID;
    }
    int minr = L;
    if (st.getmin(i, L) != l) continue;


    L = i, R = R;
    while (L < R) {
      int MID = (L + R) / 2;
      if (st.getmin(i, MID) <= l) R = MID;
      else L = MID + 1;
    }
    
    int minl = L;

    if (st.getmin(i, L) != l) continue;

    if (minl > minr) continue;

    if (minl > maxr || maxl > minr) continue;
    // debug(i, minl, minr, maxl, maxr);
    ans += min(maxr, minr) - max(maxl, minl) + 1;
  }

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
