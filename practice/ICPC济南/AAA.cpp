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

int a[N], b[N];
vector<pair<int, int> > p[N];
int now;
map<int, int> mp;


void solve() {
	int n, m; cin >> n >> m;
	int ans = 0;
	
	rep(i, 1, n) cin >> a[i], b[i] = getget(a[i]);
	sort(b + 1, b + 1 + n);
	reverse(b + 1, b + 1 + n);
	for (int i = 1; i <= n - m; i ++ ) ans += b[i];
	now = 0;
	map<int, vector<int> > vis;
	rep(i, 1, n) {
		now = i;
		deque<int> dq; 
		mp[a[i]] = 0;
		dq.push_back(a[i]);
		while (dq.size()) {
			auto t = dq.front(); dq.pop_front();
			// t >> 1
			int dist = mp[t];
			if (!mp.count(t >> 1)) {
				mp[t >> 1] = dist + 1;
				dq.push_front(t >> 1);
			}
			if (t - 1 >= 1 && !mp.count(t - 1)) {
				mp[t - 1] = dist + 1;
			}
			
			if (!mp.count(t + 1)) {
				mp[t + 1] = dist + 1;
			}
			
			if (((t + 1) >> 1) >= 1 && !mp.count((t + 1) >> 1)) {
				mp[(t + 1) >> 1] = dist + 2;
				dq.push_back((t + 1) >> 1);
			}
			
			if (((t - 1) >> 1) >= 1 && !mp.count((t - 1) >> 1)) {
				mp[(t - 1) >> 1] = dist + 2;
				dq.push_back((t - 1) >> 1);
			}
		}
		for (auto &[x, y]: mp) {
			vis[x].emplace_back(y);
		}
		mp.clear();		
	}
	
	for (auto &[k, v] : vis) {
		sort(all(v));
		// reverse(all(v));
		if (k == 15) {
			for (int &x: v) cout << x << " ";
			cout << "\n";
		}
		
		if (SZ(v) >= n - m) {
			int val = 0;
			for (int i = 0; i < n - m; i ++ ) {
				val += v[i];
			}
			if (val == 12) {
				debug(k);
			}
			chkmin(ans, val);
		}
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