#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
using namespace std;
using LL = long long;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1010, M = 10010;

int n, m, tot;
int f[N][M], w[N], v[N];
int id[N], sz[N], fa[N];
vector<int> e[N];

void dfs(int u) {
	for(int &v: e[u]) {
		dfs(v);
		sz[u] += sz[v];
	}
	sz[u] ++;
	id[u] = ++ tot;
	fa[tot] = u;
}

int main() {

 	scanf("%d%d", &n, &m);

 	for(int i = 2; i <= n; i ++ ) {
 		int x; scanf("%d", &x);
 		e[x].push_back(i);
 	}
 	for(int i =1; i <= n; i ++ ) {
 		scanf("%d", &w[i]);
 	}
 	for(int i =1; i <= n; i ++ ) {
 		scanf("%d", &v[i]);
 	}

 	dfs(1);

 	for(int j = 1; j <= m; j ++ ) f[0][j] = -1e9;
	for(int i = 1; i <= n; i ++ ) {
		int u = fa[i]; //cout << u << " \n"[i == n];
		// cout << i - sz[u] << " \n"[i == n];
		for(int j = 0; j <= m; j ++ ) {
			f[i][j] = f[i - sz[u]][j];
			
			if(j >= v[u]) {
				chkmax(f[i][j], f[i - 1][j - v[u]] + w[u]);
			}
		}
	}


 	for(int i = 0; i <= m; i ++ ) 
 		if(f[id[1]][i] > 0) printf("%d\n", f[id[1]][i]);
 		else printf("0\n");

    return 0;

}
