#include <bits/stdc++.h>
using namespace std;

int ban[27][27];
bool vis[26];
int dp[500010][27];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	for (int i = 0; i < m; i ++ ) {
		for (int j = 0; j < 26; j ++ ) if (vis[j]) {
			ban[j][t[i] - 'a'] = true;
		}
		vis[t[i] - 'a'] = true;
	}
	s = " " + s;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < 26; j ++ ) {
			dp[i][j] = dp[i - 1][j] + (!vis[s[i] - 'a']);
		}
		if (!vis[s[i] - 'a']) continue;
		dp[i][s[i] - 'a'] = max(dp[i][s[i] - 'a'], 1);
		for (int j = 0; j < 26; j ++ ) if (!ban[j][s[i] - 'a']) {
			dp[i][s[i] - 'a'] = max(dp[i][s[i] - 'a'], dp[i - 1][j] + 1);
		}
		
	}
	
	cout << *max_element(dp[n], dp[n] + 26);

	return 0;
}