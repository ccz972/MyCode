#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    int m = __lg(n) + 1;
    maxvid.resize(m); minvid.resize(m);
    
    for (int i = 0; i < m; i ++ ) maxvid[i].resize(n), minvid[i].resize(n);
    for (int i = 0; i < n; i ++ ) maxvid[0][i] = minvid[0][i] = i;
    for (int i = 1; i < m; i ++ ) {
      for (int j = 0; j <= n - (1 << i); j ++ ) {
        maxvid[i][j] = a[maxvid[i - 1][j]] > a[maxvid[i - 1][j + (1 << (i - 1))]] ? maxvid[i - 1][j] : maxvid[i - 1][j + (1 << (i - 1))];
        minvid[i][j] = a[minvid[i - 1][j]] < a[minvid[i - 1][j + (1 << (i - 1))]] ? minvid[i - 1][j] : minvid[i - 1][j + (1 << (i - 1))];
      }
    }

  }
 
  T getmaxid(int l,int r){
    int k = __lg(r - l + 1);
    return a[maxvid[k][l]] > a[maxvid[k][r - (1 << k) + 1]] ? maxvid[k][l] : maxvid[k][r - (1 << k) + 1];
  }    
  T getminid(int l,int r){
    int k = __lg(r - l + 1);
    return a[minvid[k][l]] < a[minvid[k][r - (1 << k) + 1]] ? minvid[k][l] : minvid[k][r - (1 << k) + 1];
  }    
private:
  int n;
  vector<T> a;
  // vector<vector<T>> maxv, minv;
  vector<vector<T>> maxvid, minvid;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ST st(a, n);
    function<int(int, int)> dfs = [&] (int l, int r) {
      if(l + 1 == r) return 1;
      if(l >= r) return 0;
      int mxd = st.getmaxid(l, r);
      int mid = st.getminid(l, r); 
      if(mxd > mid) swap(mxd, mid);
      return dfs(l, mxd) + (mxd != mid) + dfs(mid, r);
    };
    cout << dfs(0, n - 1) << "\n";
  }
  return 0;
}