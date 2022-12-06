/***************************************************

@File    : C.cpp
@Time    : 2022/07/15 21:46:32
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

constexpr ll INF = 1E18 + 1;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    int n, m, q; cin >> n >> m >> q;
    string s; cin >> s;
    vector<pair<ll, ll> > a(m);
    vector<ll> idx;
    idx.push_back((ll)s.size());
    for(auto &[k, v] : a) {
      cin >> k >> v;
      if(idx.back() < INF)
        idx.push_back(idx.back() + v - k + 1);
    }


    function<char(ll)> find = [&] (ll x) {
      int id = lower_bound(idx.begin(), idx.end(), x) - idx.begin();
      //这个值属于哪个区间
      debug(id, x);
      if(id == 0) {
        return s[x - 1];
      }
      ll xyq = x - idx[id - 1] + a[id - 1].first - 1;
      debug(xyq);
      return find(xyq);
      // ... ... ... [...   idx]
    };

    while(q -- ) {
      ll k; cin >> k;
      if(k <= (ll)s.size()) {
        cout << s[k - 1] << "\n";
        continue;
      }

      cout << find(k) << "\n";


    }
    
  }
  return 0;
}