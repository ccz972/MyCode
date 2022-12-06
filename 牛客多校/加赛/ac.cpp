#include<bits/stdc++.h>

#define fi first
#define endl '\n'
#define se second
#define LL long long
#define int long long
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define sp system("pause");
#define lowbit(x) ((x)&(-x))
#define sz(v) ((int)v.size())
#define ULL unsigned long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define ceil(x, y) ((x + y - 1) / y)
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, b, a) for(int i = (b); i >= (a); i--)

using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;


inline void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    rep (i, 0, n - 1) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    vector<int> p(n + 1, -1); // 存放父节点
    per (i, 2 * n - 2, 0) {
        if (p[i % n] != -1) continue;
        if (a[i + 1] == (a[i] + 1) % 3) {
            p[i % n] = (i + 1) % n;
            continue;
        }
        int cur = i + 1;
        while (p[cur % n] != -1) {
            cur = p[cur % n];
            if ((a[i] + 1) % 3 == a[cur % n]) {
                p[i % n] = cur % n;
                break;
            }
        }
    }
    
    int idx = -1;
    rep (i, 0, n - 1) {
        if (p[i] == -1) {
            if (idx == -1) idx = i;
            else {
                if (a[idx] != a[i]) {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}