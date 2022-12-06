#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    maxv.resize(n); minv.resize(n);
    maxvid.resize(n); minvid.resize(n);
    int m = __lg(n) + 1;
    for (int i = 0; i < n; i ++ ) maxv[i].resize(m), minv[i].resize(m),maxvid[i].resize(m), minvid[i].resize(m);
    for (int i = 0; i < n; i ++ ) maxv[i][0] = minv[i][0] = a[i],maxvid[i][0] = minvid[i][0] = i;
    for (int j = 1; j < m; j++) {
      for (int i = 0; i <= n - (1 << j); i++) {
        maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
        minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
        maxvid[i][j] = a[maxvid[i][j - 1]] > a[maxvid[i + (1 << (j - 1))][j - 1]] ? maxvid[i][j - 1] : maxvid[i + (1 << (j - 1))][j - 1];
        minvid[i][j] = a[minvid[i][j - 1]] < a[minvid[i + (1 << (j - 1))][j - 1]] ? minvid[i][j - 1] : minvid[i + (1 << (j - 1))][j - 1];
      }
    }
  }
  T getmax(int l,int r){
    int k = __lg(r - l + 1);
    return max(maxv[l][k], maxv[r - (1 << k) + 1][k]);
  }    
  T getmin(int l,int r){
    int k = __lg(r - l + 1);
    return min(minv[l][k], minv[r - (1 << k) + 1][k]);
  }    
  T getmaxid(int l,int r){
    int k = __lg(r - l + 1);
    return a[maxvid[l][k]] > a[maxvid[r - (1 << k) + 1][k]] ? maxvid[l][k] : maxvid[r - (1 << k) + 1][k];
  }    
  T getminid(int l,int r){
    int k = __lg(r - l + 1);
    return a[minvid[l][k]] < a[minvid[r - (1 << k) + 1][k]] ? minvid[l][k] : minvid[r - (1 << k) + 1][k];
  }    
private:
  int n;
  vector<T> a;
  vector<vector<T>> maxv, minv;
  vector<vector<T>> maxvid, minvid;
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    if(n == 1) {
      cout << "0\n";
      continue;
    }
    ST st(a, n);

    int cnt = 0;
    for(int i = 0; i < n;  ) {
      int l = i, r = n - 1;
      while(l < r) {
        int mid = (l + r + 1) / 2;
        int mx = st.getmax(i, mid); 
        if(a[i] >= mx) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      int rmx1 = st.getminid(i, l);
      l = i, r = n - 1;

      while(l < r) {
        int mid = (l + r + 1) / 2;
        int mi = st.getmin(i, mid); 
        if(a[i] <= mi) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }

      int rmx2 = st.getmaxid(i, l);

      cnt ++;

      i = max(rmx1, rmx2);
      if(i == n - 1) break;
    }
    cout << cnt << "\n";
    
  }
}