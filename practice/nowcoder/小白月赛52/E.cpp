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

constexpr int mod = 998244353;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

template<typename T> 
inline void Discrete (vector<T> &all) {
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
}

void solve() {

  int n, k; cin >> n >> k;
  vector a(n, vector<int> ());
  vector<int> all;
  for(int i = 0; i < n; i ++ ) {
    int len; cin >> len;
    a[i].resize(len);
    for(int j = 0; j < len; j ++ ) {
      cin >> a[i][j];
      all.emplace_back(a[i][j]);
      if(k > a[i][j]);
      all.emplace_back(k - a[i][j]);
    } 
  }

  Discrete(all);

  auto find = [&] (int x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };      
  
  int N = all.size();
  fenwick<ll> fen(N + 10);
  int cnt = 0;
  for(int i = 0; i < n; i ++ ) {
    if(i) cnt += (int)a[i].size();
    for(int j = 0; j < a[i].size(); j ++ ) {
      fen.modify(find(a[i][j]), 1);
    }
  }
  ll ans = 0;
  for(int i = 0; i < n - 1; i ++ ) {
    for(int j = 0; j < a[i].size(); j ++ ) {
      fen.modify(find(a[i][j]), -1);
    } 
    for(int j = 0; j < a[i].size(); j ++ ) {
      int now = a[i][j];
      if(now >= k) {
        ans = (ans + cnt) % mod;
      } else {
        now = k - now;
        int lisan = find(now);
        ans += fen.get(N) - fen.get(lisan - 1);
        ans %= mod;
      }
    }
    cnt -= a[i + 1].size();
  }

  cout << ans ;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}