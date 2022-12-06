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

const int N = 4e5 + 10;

template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    maxv.resize(n); minv.resize(n);
    int m = __lg(n) + 1;
    for(int i = 0; i < n; i ++ ) maxv[i].resize(m), minv[i].resize(m);
    for(int i = 0; i < n; i ++ ) maxv[i][0] = minv[i][0] = a[i];
    for(int j = 1; j < m; j++) {
      for(int i = 0; i <= n - (1 << j); i++) {
        maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
        minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
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
private:
  int n;
  vector<T> a;
  vector<vector<T>> maxv, minv;
};


void solve() {
  int n; ll s;
  cin >> n >> s;  
  vector<ll> a(n * 2), b(n * 2);
  ll sum = 0;
  rep(i, 0, n - 1) {
    cin >> a[i];
    sum += a[i];
    a[i + n] = a[i];
  }
  if(sum < s) {
    cout << "-1\n";
    return ;
  }
  rep(i, 0, n - 1) {
    cin >> b[i];
    b[i + n] = b[i];
  }
  ST st(b, n * 2);
  n *= 2;
  ll now = 0;
  ll mi = 1e18;
  for(int i = 0, j = 0; i < n; i ++ ) {
    while(j < n && now + a[j] < s) {
      now += a[j];
      ++ j;
    }
    if(j >= n && now < s) {
      break;
    }
    mi = min(mi, st.getmax(i, j));
    now -= a[i];
  }
  cout << mi;



}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}