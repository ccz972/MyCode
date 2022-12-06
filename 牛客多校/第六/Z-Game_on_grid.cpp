#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long LL;
typedef pair<int,int> PII;
mt19937 rnd();
const int mod = 1e9 + 7;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<char>> a(n + 1, vector<char>(m + 1));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> a[i][j];
		}
	

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int _; cin >> _;
    while(_ --){
    	solve();
    	cout << '\n';
    }
    return 0;
}