// Problem: K. Klee's Wonderful Adventure
// Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// URL: https://codeforces.com/gym/103736/problem/K
// Memory Limit: 512 MB
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

struct point {
	int x, y; 
	int p;
};

void solve() {
  int n; cin >> n;
	vector<int> v(5);
	for(int i = 1; i < 5; i ++ ) cin >> v[i];
	cin >> v[0];
	int s, T; cin >> s >> T;
	-- s, -- T;
	vector<point> a(n);
	auto get = [&] (int id) {
		int x = a[id].x, y = a[id].y;
		if(x > 0 && y > 0) return 1;
		if(x < 0 && y > 0) return 2;
		if(x < 0 && y < 0) return 3;
		return 4;
	};
	rep(i, 1, n) {
		cin >> a[i - 1].x >> a[i - 1].y;
		a[i - 1].p = get(i);
	}
	vector<double> dist(n, 1e9);
	vector<bool> vis(n);
	dist[s] = 0;
	auto Pow = [&] (int x) {
		return (ll)x * x;
	};
	auto get_distance = [&] (int id1, int id2) {
		if(get(id1) != get(id2)) {
			return sqrt( Pow(a[id1].x - a[id2].x) + Pow(a[id1].y - a[id2].y) )  / v[0];
		} else {
			return sqrt( Pow(a[id1].x - a[id2].x) + Pow(a[id1].y - a[id2].y) )  / v[get(id1)];
		}
	};
	
	for(int j = 0; j < n; j ++ ) {
		int t = -1;
		for(int i = 0; i < n; i ++ ) if(!vis[i] && (t == -1 || dist[i] < dist[t])) {
			t = i;
		}
		vis[t] = true;
		for(int i = 0; i < n; i ++ ) {
			dist[i] = min(dist[i], dist[t] + get_distance(t, i));
		}
	}
	printf("%.10lf", dist[T]);
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
