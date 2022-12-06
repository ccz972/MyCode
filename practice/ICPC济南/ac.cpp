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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n); for(int &x: a) cin >> x;
  int mx = *max_element(all(a));
  int ans = 1E9;
  for (int i = 1; i <= mx; i ++ ) {
    vector<int> b(n);
    for (int j = 0; j < n; j ++ ) b[j] = get(a[j], i);
    sort(all(b)); // reverse(all(b));
    // for (int &x :b) cout << x << " ";
    // cout << "\n";
    int ret = 0;
    // cout << n - m << " !!!\n";
    for (int j = 0; j < n - m; j ++ ) {
      ret += b[j];
    }
    
    // if (ret == 11) {
    //   cout << i << "\n";
    //   exit(0);
    // }

    // cout << i << " " << ret << "\n";
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