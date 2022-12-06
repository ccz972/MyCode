#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
using namespace std;
using LL = long long;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2010;
constexpr LL INF = 1e18;

int n, m, f[N], dep[N];
vector<array<int, 3>> path[N];
vector<int> e[N];
LL dp[N], sdp[N];

void dfs(int u) {
	for(int &v: e[u]) {
		dfs(v);
		sdp[u] += dp[v];
	}
	dp[u] = sdp[u];
	for(auto &[a, b, w]: path[u]) {
		LL tmp = sdp[u];
		int x = a;
		while(x != u) {
			tmp += sdp[x] - dp[x];
			x = f[x];
		}
		x = b;
		while(x != u) {
			tmp += sdp[x] - dp[x];
			x = f[x];
		}
		tmp += w;
		chkmax(dp[u], tmp);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
 		freopen("1.txt", "r", stdin);
 		freopen("2.txt", "w", stdout);
 	#endif
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i ++ ) {
		scanf("%d", &f[i]);
		dep[i] = dep[f[i]] + 1;
		e[f[i]].push_back(i);
	}
	for(int i = 0; i < m; i ++ ) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		int x = u, y = v;
		while(x != y) {
			if(dep[x] > dep[y]) x = f[x];
			else y = f[y];
		}
		path[x].push_back({u, v, w});
	}
	dfs(1);
	printf("%lld\n", dp[1]);

    return 0;

}

