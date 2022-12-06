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
    if (l > r) swap(l, r);
    int k = __lg(r - l + 1);
    return max(maxv[k][l], maxv[k][r - (1 << k) + 1]);
  }    
  T getmin(int l,int r){
    if (l > r) swap(l, r);
    int k = __lg(r - l + 1);
    return min(minv[k][l], minv[k][r - (1 << k) + 1]);
  }    
private:
  int n;
  vector<T> a;
  vector<vector<T>> maxv, minv;
};

void solve() {
  int n; cin >> n; n <<= 1;
  vector<int> a(n);
  for (int i = 0; i < n / 2; i ++ ) {
    cin >> a[i]; a[i + n / 2] = a[i]; 
  }
  ST st(a, n);
  int id = 0;
  for (int i = 0; i < n / 2; i ++ ) if (a[i] > a[id]) {
    id = i;
  }
  n /= 2;
  long long ans = INT64_MIN;
  for (int i = id + 1; i < id + n - 2; i ++ ) {
    chkmax(ans, (ll)st.getmax(id, i) - st.getmin(id, i) + st.getmax(i + 1, id + n - 1) - st.getmin(i + 1, id + n - 1));
  }
  id += n;
  for (int i = id - 1; i > id - n + 2; i -- ) {
    chkmax(ans, (ll)st.getmax(i, id) - st.getmin(i, id) + st.getmax(i - 1, id - n + 1) - st.getmin(i - 1, id - n + 1));
  }
  cout << ans << "\n";
  
}

void solve2() {
  int n; cin >> n;
  vector<int> a(n); for (int &x: a) cin >> x;
  int mx = *max_element(a.begin(), a.end());
  int mi = *min_element(a.begin(), a.end());
  nth_element(a.begin(), a.begin() + 1, a.end());
  int cmi = a[1];
  nth_element(a.begin(), a.begin() + 1, a.end(), [&](int x, int y) {
    return x > y;
  });
  int cmx = a[1];
  cout << mx + cmx - mi - cmi << "\n";
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve2();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
