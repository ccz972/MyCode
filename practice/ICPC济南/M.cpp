#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PII pair<int, int>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define debug(x) cout << #x << " : " << x << "\n"
mt19937 rng(random_device{}());

void solve() {
	int n; cin >> n;
	vector<string> a(n); for (auto &x: a) cin >> x;
	int ans = 0;
	auto now = a[0];
	reverse(all(now));
	Rep(i, 1, n) {
		auto nnow = a[i];
		reverse(all(nnow));		
		if (SZ(now) < SZ(nnow)) now.swap(nnow);
		int t = 0;
		for (int j = 0; j < max(SZ(nnow), SZ(now)); j ++ ) {
			ans += t;
			int p = t;
			if (j < SZ(nnow)) p += nnow[j] - '0';
			if (j < SZ(now)) p += now[j] - '0';
			if (p >= 10) t = 1;
			else t = 0;
			p %= 10;
			now[j] = '0' + p;
		}
		if (t) {
			now.push_back('0' + t);
		}
		ans += t;
		
	}
	
	cout << ans << "\n";
	
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
// 	
	// ans = 0;
	// now = a[0];
	// reverse(all(now));
	// Rep(i, 1, n) {
		// auto nnow = a[i];
		// reverse(all(nnow));		
		// if (SZ(now) < SZ(nnow)) now.swap(nnow);
// 		
		// for (int j = 0, t = 0; j < max(SZ(nnow), SZ(now)); j ++ ) {
			// int p = t;
			// if (j < SZ(nnow)) p += nnow[j] - '0';
			// if (j < SZ(now)) p += now[j] - '0';
			// t = (p >= 10);
			// p %= 10;
			// now[j] = '0' + p;
			// ans += t;
		// }
	// }
// 	
// 	
	// cout << ans << "\n";
// 	
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
// 	
	// ans = 0;
	// now = a[0];
	// reverse(all(now));
	// Rep(i, 1, n) {
		// auto nnow = a[i];
		// reverse(all(nnow));		
		// if (SZ(now) < SZ(nnow)) now.swap(nnow);
// 		
		// for (int j = 0, t = 0; j < max(SZ(nnow), SZ(now)); j ++ ) {
			// int p = t;
			// if (j < SZ(nnow)) p += nnow[j] - '0';
			// if (j < SZ(now)) p += now[j] - '0';
			// t = (p >= 10);
			// p %= 10;
			// now[j] = '0' + p;
			// ans += t;
		// }
	// }
// 	
// 	
	// cout << ans << "\n";
// 	
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
// 	
	// ans = 0;
	// now = a[0];
	// reverse(all(now));
	// Rep(i, 1, n) {
		// auto nnow = a[i];
		// reverse(all(nnow));		
		// if (SZ(now) < SZ(nnow)) now.swap(nnow);
// 		
		// for (int j = 0, t = 0; j < max(SZ(nnow), SZ(now)); j ++ ) {
			// int p = t;
			// if (j < SZ(nnow)) p += nnow[j] - '0';
			// if (j < SZ(now)) p += now[j] - '0';
			// t = (p >= 10);
			// p %= 10;
			// now[j] = '0' + p;
			// ans += t;
		// }
	// }
// 	
// 	
	// cout << ans << "\n";
// 	
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
	// shuffle(all(a), rng);
// 	
	// ans = 0;
	// now = a[0];
	// reverse(all(now));
	// Rep(i, 1, n) {
		// auto nnow = a[i];
		// reverse(all(nnow));		
		// if (SZ(now) < SZ(nnow)) now.swap(nnow);
// 		
		// for (int j = 0, t = 0; j < max(SZ(nnow), SZ(now)); j ++ ) {
			// int p = t;
			// if (j < SZ(nnow)) p += nnow[j] - '0';
			// if (j < SZ(now)) p += now[j] - '0';
			// t = (p >= 10);
			// p %= 10;
			// now[j] = '0' + p;
			// ans += t;
		// }
	// }
// 	
// 	
	// cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	while (T -- )
	solve();
	
	return 0;
}