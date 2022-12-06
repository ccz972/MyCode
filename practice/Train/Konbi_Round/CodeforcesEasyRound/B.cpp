#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;
//使用的时候注意判断如果 多个最值 取左边下标还是右边下标
//分别对应 >= >   <= <
template<typename T> 
class ST{
  public:
  ST(vector<T> a, int _n) : a(a), n(_n) { // cope with in [0,n-1] 
    lg.resize(n + 1); lg[1] = 0; 
    for (int i = 2; i <= n; i ++ ) lg[i] = lg[i >> 1] + 1;
    int m = lg[n] + 1;
    G.resize(m); // minv.resize(m);
    
    for (int i = 0; i < m; i ++ ) G[i].resize(n); // minv[i].resize(n); 
    for (int i = 0; i < n; i ++ ) G[0][i] = a[i];

    for (int i = 1; i < m; i ++ ) {
      for (int j = 0; j <= n - (1 << i); j ++ ) {
        G[i][j] = gcd(G[i - 1][j], G[i - 1][j + (1 << (i - 1))]);
      }
    }

  }
  T getgcd(int l,int r){
    int k = lg[r - l + 1];
    return gcd(G[k][l], G[k][r - (1 << k) + 1]);
  }    
private:
  int n;
  vector<T> a;
  vector<int> lg;
  vector<vector<T>> G;
  // vector<vector<T>> maxv, minv;
  // vector<vector<T>> maxvid, minvid;
};

void solve() {
  int n; ll k; cin >> n >> k;
  vector<int> a(n); for (int &x: a) cin >> x;

  if (k == 1) return cout << 1ll * n * (n + 1) / 2 << "\n", void();
  
  map<int, int> mp;

  for (ll i = 2; i * i <= k; i ++ ) while (k % i == 0) {
    mp[i] ++;
    k /= i;
  }
  if (k != 1) mp[k] ++;

  
  
  ll ans = 0;

  map<int, int> cnt;

  auto chk = [&] () {
    for (auto [k, v]: mp) {
      if (cnt[k] < v) return false;
    }
    return true;
  };

  auto add = [&] (int x) {
    for (auto [k, v]: mp) if (x % k == 0) {
      while (x % k == 0) {
        ++ cnt[k];
        x /= k;
      }
    }
  };

  auto del = [&] (int x) {
    for (auto [k, v]: mp) if (x % k == 0) {
      while (x % k == 0) {
        -- cnt[k];
        x /= k;
      }
    }
  };

  for (int i = 0, j = -1; i < n; i ++ ) {
    while (j + 1 < n && !chk()) {
      ++ j;
      add(a[j]);
    }
    //0 1 2 
    if (chk()) {
      ans += n - j;
      // debug(i, j, n - j);
    }
    
    del(a[i]);
  }

  cout << ans << "\n";

  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}