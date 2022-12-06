#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define dec(i, a, b) for(int i = (a); i >= (b); i -- )
using namespace std;
using LL = long long;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1010, M = 10010;

int n, m, tot;
int f[N][M], w[N], v[N], id[N], l[N], r[N];
vector<int> e[N];

void dfs(int u) {
	l[u] = ++ tot;
	id[tot] = u;
	for(auto &v: e[u]) {
		dfs(v);
	}
	r[u] = tot;
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
 	for(int j = 1; j <= m; j ++ ) f[n + 1][j] = -1e9;

  dec(i, n, 1) {
    int u = id[i];
    rep(j, 0, m) {
      f[i][j] = f[r[u] + 1][j];
      if(j >= v[u]) {
        chkmax(f[i][j], f[i + 1][j - v[u]] + w[u]);
      }
    }
  }

 	// for(int i = n; i >= 1; i -- ) {
 	// 	int u = id[i];
 	// 	for(int j = 0; j <= m; j ++ ) {
 	// 		f[i][j] = f[r[u] + 1][j];
 	// 		if(j >= v[u]) {
  //       chkmax(f[i][j], f[i + 1][j - v[u]] + w[u]);
  //       // cout << id[i] << " " << id[i + 1] << "\n";
  //     }
 				
 	// 	}
 	// }

 	for(int i = 0; i <= m; i ++ ) 
 		if(f[1][i] > 0) printf("%d\n", f[1][i]);
 		else printf("0\n");

    return 0;

}
