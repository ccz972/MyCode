// Problem: Permutation Counting
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/36091/H
// Memory Limit: 1048576 MB
// Time Limit: 6000 ms
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

struct DSU {
  std::vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return leader(x) == leader(y); }
  bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return false;
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
};


constexpr int N = 2e6 + 10;
constexpr int mod = 998244353;

int fact[N + 1], infact[N + 1];

ll ksm(ll a, ll b, ll ret = 1) {
	while(b) {
		if(b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}

void init() {
	fact[0] = infact[0] = 1;
	for(int i = 1; i <= N; i ++ ) {
		fact[i] = (ll)fact[i - 1] * i % mod;
	}
	infact[N] = ksm(fact[N], mod - 2);
	for(int i = N - 1; i >= 1; i -- ) {
		infact[i] = (ll)infact[i + 1] * (i + 1) % mod;
	} 
}

ll C(int n, int m) {
	if(n < m) return 0;
	return (ll)fact[n] * infact[m] % mod * infact[n - m] % mod;
} 

int h[N], e[N], ne[N], idx;
int d[N], sz[N], all[N];
ll f[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs1(int u) {
	for(int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		dfs1(j);
		sz[u] += sz[j];
	}
}

void dfs2(int u) {
	int now = sz[u] - 1;
	ll ans = 1;
	for(int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		dfs2(j);
		ans = (ans * C(now, sz[j])) % mod * f[j] % mod;
		now -= sz[j];
	}
	f[u] = ans;
}

void solve() {
	init();
  int n, m; cin >> n >> m;
  memset(h, -1, sizeof h);
  DSU dsu(n + 1);
  rep(i, 1, n + 1) {
  	sz[i] = 1;
  }
  
  rep(i, 1, m) {
  	int u, v; cin >> u >> v;
  	d[u] ++;
  	add(v, u);
  	if(dsu.same(u, v)) {
  		cout << "0\n";
  		return ;
  	}
  	dsu.merge(u, v);
  	
  }
  
  rep(i, 1, n) if(!d[i]) {
  	add(n + 1, i);
  }
  
  dfs1(n + 1);
  dfs2(n + 1);

	cout << f[n + 1];
	
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T --) solve();


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
