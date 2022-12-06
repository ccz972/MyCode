/***************************************************

@File    : D.cpp
@Time    : 2022/07/24 23:33:00
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

constexpr ll INF = 1E18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n, m; cin >> n >> m;
    
    struct node {ll pos, k; bool operator < (const node& T) const {
      if(pos != T.pos) return pos < T.pos;
      return k < T.k;
    }};


    vector<node> all;
    vector<ll> a(n), p(n);    
		all.push_back({-INF, 0});
		all.push_back({INF, 0});
    for(int i = 0; i < n; i ++ ) {
      cin >> a[i] >> p[i];
      all.push_back({a[i] - p[i] + 1, 1});
      all.push_back({a[i] + 1, -2});
      all.push_back({a[i] + p[i] + 1, 1});
    }

    sort(all.begin(), all.end());


		int mm = all.size();

		vector<ll> d(mm);
		ll mx = -INF, mi = INF;
		auto update = [&] (ll id, ll val) {
			if(val <= m) return ; //小于 m 删除他自己一定合法
			chkmax(mx, val + id - m);
			chkmin(mi, id - val + m);
		};

		ll pre = 0;
		for(int i = 1; i < mm - 1; i ++ ) {
			d[i] = d[i - 1] + all[i].k; //前缀和
			if(all[i].pos != all[i + 1].pos) { //可能有重复的地方，只需要取最后一个即可
				update(all[i].pos, pre + d[i]);
				update(all[i + 1].pos - 1, pre + d[i] * (all[i + 1].pos - all[i].pos));
			}
			pre += d[i] * (all[i + 1].pos - all[i].pos); //前缀和的时候从 当前pos 到 下一个pos 的贡献
		}
    
		for(int i = 0; i < n; i ++ ) { 
			if((a[i] + p[i]) >= mx && (a[i] - p[i]) <= mi) cout << "1";
			else cout << "0";
		}
		cout << "\n";
    
    




  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}