#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<int> p(n + 10), q(n + 10), s(2 * n + 10);
	vector<vector<long long>> f(n + 10, vector<long long>(n + 10));
	f[0][0] = 1;
	for(int i = 1; i <= n; i ++) cin >> p[i];
	for(int i = 1; i <= n; i ++) cin >> q[i];
	for(int i = 1; i <= 2 * n; i ++) cin >> s[i];
	for(int i = 0; i <= n; i ++){
		for(int j = 0; j <= n; j ++){
			if(i + j == 0) continue;
			if(s[i + j] == p[i]) f[i][j] += f[i - 1][j];
			if(s[i + j] == q[j]) f[i][j] += f[i][j - 1];
			f[i][j] %= mod;
		}
	}
	cout << f[n][n] << "\n";
} 
int main() {
  freopen("data.txt", "r", stdin);
  // freopen("out2.txt", "w", stdout);
  int T; cin >> T;
  T = 2;
  while(T -- )
  solve();
  return 0;
}