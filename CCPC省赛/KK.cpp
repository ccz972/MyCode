#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;

int f[N], p[N];

// vector<int> mp[N];
vector<int> s[N];
int cnt[N];
bool vis[N];
vector<int> son[N];
vector<int> a;
vector<int> dp[N];

int deg[N];
int q[N];
// int sum;

void find(int u) {
    vis[u] = true;
    a.emplace_back(u);
    int F = f[u];
    while (F != u) {
        vis[F] = true;
        a.emplace_back(F);
        F = f[F];
    }
}

// void dfs(int u, int fa) {
//     for (int &v: son[u]) if (v != fa) {
//         ++ sum;
//         dfs(v, u);
//     }
// }
// int FF = 0;
void DFS(int u, int fa, int dep , int sz) {
    // ++ FF;
    // if (FF >= 10) return ;
    if (!vis[u]) {
        // cout << dep << "\n";
        if ((int)dp[sz].size() < dep) {
            dp[sz].emplace_back(1);
        } else {
            dp[sz][dep - 1] ++;
        }
    }
    for (int &v: son[u]) if (v != fa && !vis[v]) {
        // cout << v << " |||\n";
        DFS(v, u, dep + 1, sz);
    }
}

void solve() {
    int n; cin >> n;    
    for (int i = 1; i <= n; i ++ ) {
        cin >> f[i];
        ++ deg[f[i]];
        son[f[i]].emplace_back(i);
    }

    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ ) if (!deg[i]) {
        q[++ tt] = i;
    }

    while (hh <= tt) {
        int t = q[hh ++ ];
        if (-- deg[f[t]] == 0) {
            q[++ tt] = f[t];
        }
    }

        


    // for (int i = 1; i <= n; i ++ ) if (deg[i]) {
    //     cout << i << "\n";
    // }

    // for (int i = 1; i <= n; i ++ ) {
    //     cout << "i = " << i << endl;
    //     for (int x: son[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    // exit(0);

    for (int i = 1; i <= n; i ++ ) if (deg[i] && !vis[i]) {
        find(i);
        // cout << vis[1] << " " << vis[2] << "\n";
        // return ;
        if (a.empty()) continue;
        int sz = a.size();
        ++ cnt[sz];
        for (int x: a) {
            // sum = 0;
            DFS(x, 0, 0, sz);
            // dfs(x, 0);
            // if (sum) {
            //     mp[sz].emplace_back(sum);
            // }
        }
        a.clear();
    }

    // for (int x: dp[1]) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    int m = 0;

    for (int i = 1; i <= n; i ++ ) if (cnt[i]) {
        p[++ m] = i;
        int now = p[m];
        if (dp[now].empty()) continue;
        // if (mp[i].empty()) continue;
        // sort(mp[i].begin(), mp[i].end());

        s[now].resize(dp[now].size());
        for (int j = 0; j < dp[i].size(); j ++ ) {
            s[now][j] = dp[now][j];
            if (j) {
                s[now][j] += s[now][j - 1];
            }
        }
        // for (int j = 0; j < mp[i].size(); j ++ ) {
        //     s[i][j] = mp[i][j];
        // }
        // for (int j = 1; j < mp[i].size(); j ++ ) {
        //     s[i][j] += s[i][j - 1];
        // }
    }

    int Q; cin >> Q;
    while (Q -- ) {
        ll A, B; cin >> A >> B;
        if (A == B) {
            cout << n << "\n";
            continue;
        }
        if (A < B) swap(A, B);
        ll t = abs(A - B);
        ll ans = 0;
        for (int i = 1; i <= m; i ++ ) if (t % p[i] == 0) {
            int now = p[i];
            ans += 1ll * now * cnt[now];
            if (!dp[now].empty()) {
                ans += s[now][min((ll)s[now].size(), B) - 1];
                // if (B >= dp[now].back()) {
                //     ans += s[now].back();
                // } else if (B <= dp[now].front()) {

                //     ans += 1ll * B * (ll)s[now].size();
                // } else {
                //     ans += s[now][B - 1];
                //     ans += B * ((int)s[now].size() - B);
                // }
            } 
        }
        cout << ans << "\n";
    }

    // for (int x: mp[1]) {
    //     cout << x << " ";
    // }
    // cout << "\n\n\n";

    // int Q; cin >> Q;
    // while (Q -- ) {
    //     ll a, b; cin >> a >> b;
    //     if (a < b) swap(a, b);
    //     ll t = abs(a - b);
    //     ll ans = 0;
    //     for (int i = 1; i <= m; i ++ ) if (t % p[i] == 0) {
    //         // cout << p[i] << " ";
    //         ans += 1ll * p[i] * cnt[p[i]];
    //         cout << ans << "\n";
    //         if (!mp[p[i]].empty()) {
    //             if (b >= mp[p[i]].back()) {
    //                 cout << b << " " << mp[p[i]].size() << " 11 \n";
    //                 ans += s[p[i]].back();
    //             } else if (b <= mp[p[i]].front()) {
    //                 cout << b << " " << mp[p[i]].size() << " 22 \n";
    //                 ans += 1ll * b * (ll)s[p[i]].size();

    //             } else {
    //                 int idx = upper_bound(mp[p[i]].begin(), mp[p[i]].end(), b) - mp[p[i]].begin();
    //                 cout << idx << "\n";
    //                 ans += s[p[i]][idx - 1];
    //                 //
    //                 ans += b * ((int)s[p[i]].size() - idx);
    //             }
    //         }
    //     }
    //     cout << ans << "\n";
    // }
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; // cin >> T;
    while (T -- ) solve();
    return 0;
}