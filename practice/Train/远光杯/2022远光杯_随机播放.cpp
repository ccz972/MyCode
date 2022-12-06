// #23. 「2022 远光杯」随机播放
// URL: https://oj.kexie.club/problem/23
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 

#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }


constexpr int N = 4010;
constexpr int mod = 1e9 + 7;

ll f[2][11][N];
ll pp[11], np[11];
ll sum, inv;

ll ksm(ll a, ll b, ll ret = 1) {
	while(b) {
		if(b & 1) ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}

void solve() {
	int n, m, t, k; cin >> n >> m >> t >> k;
	rep(i, 1, n) cin >> pp[i], sum += pp[i];
	rep(i, 1, n) np[i] = ksm(sum - pp[i], mod - 2);
	inv = ksm(sum, mod - 2);
	rep(i, 1, n) {
		f[1][i][i == t] = pp[i] * inv % mod;
	}
	rep(i, 2, m) {
		memset(f[i & 1], 0, sizeof f[i & 1]);
		rep(j, 1, n) {
			rep(p, 0, min(k, i - 1)) {
				rep(q, 1, n) if(j != q) {
					ll &ret = f[i & 1][q][p + (q == t)];
					ret += f[(i + 1) & 1][j][p] * pp[q] % mod * np[j] % mod;
					ret %= mod;
				}
			}
		}
	}
	
	ll ans = 0;
	rep(i, 1, n) {
		ans += f[m & 1][i][k];
		ans %= mod;
	}
	cout << ans << "\n";

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
