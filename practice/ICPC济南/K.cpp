#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PII pair<int, int>
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define debug(x) cout << #x << " : " << x << "\n"

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x: a) cin >> x;
	vector<int> last(n + 1, -1);
	int ans = 0;
	for (int i = 0; i < n; i ++ ) {
		if (a[i] == n) {
			++ ans;
			last[n] = 1;
		} else {
			if (last[a[i] + 1] != -1) {
				last[a[i]] = 1;
			} else {
				last[a[i]] = 1;
				++ ans;
			}
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