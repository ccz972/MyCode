#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(x, y) (x) = (x) >= (y) ? (x) : (y)
#define chkmin(x, y) (x) = (x) <= (y) ? (x) : (y)
#define PII pair<int, int>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define debug(x) cout << #x << " : " << x << "\n"

mt19937 rng(random_device{}());
int rnd(int x) {
	return rng() % x;
}

int get(int x, int y) {
	//x -> y
	int ans = abs(x - y);
	if (x < y) return ans;
	int cnt = 0;
	while (x / 2 >= y) {
		x /= 2;
		++ cnt;
		chkmin(ans, abs(x - y) + cnt);
	}
	x /= 2;
	++ cnt;
	chkmin(ans, abs(x - y) + cnt);	
	return ans;
}

// map<int, vector<int> > mp;

int getget(int x, int ret = 0) {
	while (x != 1) {
		x >>= 1;
		ret ++;
	}
	return ret;
}


constexpr int N = 510;
constexpr int M = 2E5 + 10;
int a[N], b[N];
vector<pair<int, int> > p[N];
int num[M];

void solve() {
	int n, m; cin >> n >> m;
	ll ans = 0;
	
	rep(i, 1, n) cin >> a[i], b[i] = getget(a[i]);
	sort(b + 1, b + 1 + n);
	
	for (int i = 1; i <= n - m; i ++ ) ans += b[i];
	
	int numn = 0;
	
	rep(i, 1, n) {
		auto x = a[i];
		while (x >= 1) {
			num[numn ++ ] = x;
			x /= 2;
		}
	}
	
	sort(num, num + numn);
	int mm = unique(num, num + numn) - num;
	
	for (int i = 0; i < mm; i ++ ) {
		int x = num[i];
		ll ret = 0;
		rep(i, 1, n) b[i] = get(a[i], x);
		sort(b + 1, b + 1 + n);
		for (int i = 1; i <= n - m; i ++ ) ret += b[i];
		chkmin(ans, ret);
	}
	
	cout << ans << "\n";
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	while (T -- )
	solve();
	
	return 0;
}