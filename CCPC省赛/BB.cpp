#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
	#include <debugger>
	clock_t start = clock();
#else
	#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
constexpr int P = 998244353;
int val[1000];
ll fact[1000];
void solve() {
	string s; cin >> s;
	int n = s.size();
	s = " " + s + s;
	// s = s + s;
	val['a'] = 1, val['e'] = 2, val['h'] = 3, val['n'] = 4;
	fact[0] = 1;
	for (int i = 1; i <= 20; i ++ ) {
		fact[i] = fact[i - 1] * 31 % P;
	}
	auto get = [&] (int l, int r) {
		int S = r - l + 1;
		ll ret = 0;
		for (int i = 1; i <= S; i ++ ) {
			ret += fact[S - i] * val[s[i + l - 1]];
      ret %= P;
		}
		return ret;
	};
	ll ans = 0;
	// if (n > 10) {
  vector<array<ll, 21> > VAL(n * 2 + 10);

  for (int i = 2 * n; i >= 1; i -- ) {
    ll ret = 0;
    for (int j = 0; j < 20 && i - j >= 1; j ++ ) {
      ret += val[s[i - j]] * fact[j];
      ret %= P;
      VAL[i - j][j + 1] = ret;
    }
  }


	for (int st = 1; st <= min(20, n); st ++ ) {
		vector<array<ll, 21> > dp(n * 2 + 10);
    vector<ll> mx(n * 2 + 10);
		for (int i = st; i < st + n; i ++ ) {
			//dp[i][j] 表示前i个最后一段是以i开始，长度为 j , 前i个的的最大哈希值
			//dp[i][j]
			// 
			for (int j = 1; j <= 20 && i + j - 1 <= st + n - 1; j ++ ) {
				// ll ret = get(i, i + j - 1);
        ll ret = VAL[i][j];
				if (i == st) {
					dp[i][j] = ret;
          chkmax(mx[i + j - 1], dp[i][j]);
				} else {
          chkmax(dp[i][j], mx[i - 1] + ret);
          chkmax(mx[i + j - 1], dp[i][j]);
					// for (int k = 1; k <= 20 && st + k - 1 <= i; k ++ ) {
					// 	chkmax(dp[i][j], dp[i - k][k] + ret);
					// 	// chkmax(dp[i][j], dp[i - k][k] + val(i, i + j))	
					// }
				}
			} 
		}
		for (int i = 1; i <= min(20, n); i ++ ) {
			chkmax(ans, dp[st + n - i][i]);
		}
	}
	cout << ans << "\n";
	// } 
	// else {
	// 	// baoli 
	// 	//
	// }


}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
#ifdef LOCAL
	clock_t ends = clock();
	// cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
	return 0;
}
