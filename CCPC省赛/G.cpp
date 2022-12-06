#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1010][4005];
int ans[4005];
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        for (int j = 1; j <= m; j ++ ) {
            a[i][j] = (s[j - 1] - '0');
            ans[j] &= a[i][j];
        }
    }
    
    int q; cin >> q;
    while (q -- ) {
        int i, j, l, r, p;
        cin >> i >> j >> l >> r >> p;
    }

    int ret = 0;
    for (int i = 1; i <= m; i ++ ) {
        ret += ans[i];
    }
    cout << ret << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; // cin >> T;
    while (T -- ) solve();
    return 0;
}