/***************************************************

@File    : D.cpp
@Time    : 2022/07/17 13:10:13
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
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




int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; ll x, y; cin >> n >> x >> y;
  vector<ll> a(n + 1);
  vector<ll> all;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    a[i] = a[i] + a[i - 1] - y;
    all.push_back(a[i] + x);
  }
  Discrete(all);
  auto find = [&] (ll x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };  
  int m = all.size();
  fenwick<int> fen(m + 100);
  ll ans = 0;
  for(int i = 1; i <= n; i ++ ) {
    if(a[i] <= x) {
      ++ ans;
    }
    int p = find(a[i]);
    ans += fen.get(m + 10) - fen.get(p - 1);
    fen.modify(find(a[i] + x), 1);

  }
  cout << ans << "\n";
  return 0;
}