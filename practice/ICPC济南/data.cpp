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
int rnd(int x) {
	return rng() % x;
}
int n;
vector<string> a;
void get() {
	n = rnd(5) + 1;
	a.clear();
	a.resize(n);
	rep(i, 1, n) {
		a[i - 1] = to_string(rnd(50) + 1);
	}
}

int gen() {
	shuffle(all(a), rng);
	shuffle(all(a), rng);
	shuffle(all(a), rng);
	shuffle(all(a), rng);
	int ans = 0;
	auto now = a[0];
	reverse(all(now));
	// debug(now);
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
			// t = (p >= 10);
			if (p >= 10) t = 1;
			else t = 0;
			p %= 10;
			now[j] = '0' + p;

		}
		// cout << now << " " << t << " " << ans << "\n";
		if (t) {
			// debug(now);
			now.push_back('0' + t);
			// debug(now);
		}
		ans += t;
		
	}
	return ans;
}

void solve() {
	get();
	set<int> s;
	for (int i = 0; i < 10000; i ++ ) {
		auto now = gen();
		s.insert(now);
		// s.insert(gen());
	}
	if (SZ(s) != 1) {
		for (int x: s) cout << x << " ";
		cout << "\n";
		cout << n << "\n";
		for (auto &x: a) {
			cout << x << " ";

		}
					exit(0);
	}
	// cout << SZ(s) << "\n";
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;  cin >> T;
	while (T -- )
	solve();
	cout << "\n";
	
	return 0;
}