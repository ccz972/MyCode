#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150;
const double eps = 1e-8;
int read() {
	char ch; int x, f = 1; while(ch = getchar(), ch < '!' || ch == '-') if(ch == '-') f = -1;
	x = ch - 48; while(ch = getchar(), ch > '!') x = (x << 3) + (x << 1) + ch - 48; return x *= f;
}
int n, m, line, id[MAXN]; double a[MAXN][MAXN];

void solve() {
  line = 0;
  n = read(), m = read(); srand(time(0));
  for (int i = 0; i <= max(n, m) + 1; i ++ ) id[i] = 0;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n+1; ++j)
			a[i][j] = read();
	line = 1; //分开记录当前方程和当前主元以便调换消元顺序
	for(int i = 1; i <= n; ++i) {
		int _max = line;
		for(int j = line+1; j <= m; ++j)
			if(fabs(a[j][i]) > fabs(a[_max][i])) _max = j;
		if(!a[_max][i]) continue;
		for(int j = 1; j <= n+1; ++j) swap(a[line][j], a[_max][j]);
		for(int j = 1; j <= m; ++j) {
			if(j == line) continue;
			double t = 1.0 * a[j][i] / a[line][i];
			for(int k = i+1; k <= n+1; ++k)
				a[j][k] -= a[line][k] * t;
		} id[i] = line; ++line;
	}
	vector <int> tt;
	for(int i = 1; i <= m; ++i) if(!id[i]) tt.push_back(i);
	for(int j = 0; line <= m; ++line, ++j) id[tt[j]] = line;
	//给剩下主元随便分配一个剩下的方程
	for(int i = 1; i <= n; ++i) if(!a[id[i]][i] && a[id[i]][n+1]) {puts("YES"); return;}
  puts("NO");

	// for(int i = 1; i <= n; ++i) if(!a[id[i]][i] && !a[id[i]][n+1]) {puts("0"); return;}
	// for(int i = 1; i <= n; ++i) printf("x%d=%.2lf\n", i, fabs(a[id[i]][n+1] / a[id[i]][i]) < eps ? 0.0 : a[id[i]][n+1] / a[id[i]][i]);
}

int main() {
  int T = read();
  while (T -- ) {
    solve();
  }
	
}
