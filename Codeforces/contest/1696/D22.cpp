#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    int m = __lg(n) + 1;
    maxv.resize(m); minv.resize(m);
    maxvid.resize(m); minvid.resize(m);
    
    for (int i = 0; i < m; i ++ ) maxv[i].resize(n), minv[i].resize(n),maxvid[i].resize(n), minvid[i].resize(n);
    for (int i = 0; i < n; i ++ ) maxv[0][i] = minv[0][i] = a[i], maxvid[0][i] = minvid[0][i] = i;
    for (int i = 1; i < m; i ++ ) {
      for (int j = 0; j <= n - (1 << i); j ++ ) {
        maxv[i][j] = max(maxv[i - 1][j], maxv[i - 1][j + (1 << (i - 1))]);
        minv[i][j] = min(minv[i - 1][j], minv[i - 1][j + (1 << (i - 1))]);
        maxvid[i][j] = a[maxvid[i - 1][j]] > a[maxvid[i - 1][j + (1 << (i - 1))]] ? maxvid[i - 1][j] : maxvid[i - 1][j + (1 << (i - 1))];
        minvid[i][j] = a[minvid[i - 1][j]] < a[minvid[i - 1][j + (1 << (i - 1))]] ? minvid[i - 1][j] : minvid[i - 1][j + (1 << (i - 1))];
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