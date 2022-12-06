// Problem: P1462 通往奥格瑞玛的道路
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1462
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }

struct node {
	int ver, d;
	bool operator <(const node &T) const {
		return d > T.d;
	}
};

void solve() {
  int n, m, s, t; ll h; cin >> n >> m >> s >> t >> h;
  -- s, -- t;
  vector<int> f(n);
  for(int &x: f) cin >> x;
  vector<vector<array<int, 2> > > son(n);
  for(int i = 0; i < m; i ++ ) {
  	int a, b, c; cin >> a >> b >> c;
  	-- a, -- b;
  	son[a].push_back({b, c});
  	son[b].push_back({a, c});
  }
  
  int l = max(f[s], *min_element(f.begin(), f.end())), r = *max_element(f.begin(), f.end());
	
	auto chk = [&] (int x) {
		
		priority_queue<node> q;
		q.push({s, 0});
		vector<ll> dist(n, 1e18);
		vector<bool> st(n);
		dist[s] = 0;
		
		while(q.size()) {
			auto t = q.top(); q.pop();
			int u = t.ver, d = t.d;
			if(st[u]) continue;
			st[u] = true;
			for(auto [v, w] : son[u]) {
				if(f[v] > x) continue;
				if(dist[v] > d + w) {
					dist[v] = d + w;
					q.push({v, d + w});
				}
			}
		}
		return dist[t] <= h;
		
	};
	
	while(l < r) {
		int mid = (l + r) / 2;
		if(chk(mid)) r = mid;
		else l = mid + 1;
	}
	if(!chk(l)) cout << "-1\n";
	else cout << l << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	solve();

  return 0;
}
/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */