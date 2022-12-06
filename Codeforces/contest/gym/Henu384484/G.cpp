#include <bits/stdc++.h>
using namespace std;

template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    maxv.resize(n); minv.resize(n);
    int m = __lg(n) + 1;
    for(int i = 0; i < n; i ++ ) maxv[i].resize(m), minv[i].resize(m);
    for(int i = 0; i < n; i ++ ) maxv[i][0] = minv[i][0] = i;
    for(int j = 1; j < m; j++) {
      for(int i = 0; i <= n - (1 << j); i++) {
        minv[i][j] = a[minv[i][j - 1]] < a[minv[i + (1 << (j - 1))][j - 1]] ? minv[i][j - 1] : minv[i + (1 << (j - 1))][j - 1];
        maxv[i][j] = a[maxv[i][j - 1]] <= a[maxv[i + (1 << (j - 1))][j - 1]] ? maxv[i][j - 1] : maxv[i + (1 << (j - 1))][j - 1];
        
      }
    }
  }
  T getl(int l,int r){
    int k = __lg(r - l + 1);
    return a[minv[l][k]] < a[minv[r - (1 << k) + 1][k]] ? minv[l][k] : minv[r - (1 << k) + 1][k];
  }    
  T getr(int l,int r){
    int k = __lg(r - l + 1);
    return a[maxv[l][k]] <= a[maxv[r - (1 << k) + 1][k]] ? maxv[l][k] : maxv[r - (1 << k) + 1][k];
  }    
private:
  int n;
  vector<T> a;
  vector<vector<T>> maxv, minv;
};



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int &x: a) cin >> x;
  ST st(a, n);
  while(m -- ) {
    int id, x; cin >> id >> x;
    // -- x;
    -- id;
    int l = st.getl(max(0, id - x), id);
    int r = st.getr(id, min(n - 1, id + x));
    int ans;
    if(min(a[l], a[r]) == a[id]) {
      ans = id;
    } else if (a[l] < a[r]) {
      ans = l;
    } else {
      ans = r;
    }
    cout << ans + 1 << "\n";
  }

  return 0;
}