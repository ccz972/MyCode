#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;

int f[N], p[N];

vector<int> s[N];
int cnt[N];
bool vis[N];
vector<int> son[N];
vector<int> a;
vector<int> dp[N];

int deg[N];
int q[N];

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

void DFS(int u, int fa, int dep , int sz) {
    if (!vis[u]) {
        if ((int)dp[sz].size() < dep) {
            dp[sz].emplace_back(1);
        } else {
            dp[sz][dep - 1] ++;
        }
    }
    for (int &v: son[u]) if (v != fa && !vis[v]) {
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


    for (int i = 1; i <= n; i ++ ) if (deg[i] && !vis[i]) {
        find(i);
        if (a.empty()) continue;
        int sz = a.size();
        ++ cnt[sz];
        for (int x: a) {
            DFS(x, 0, 0, sz);

        }
        a.clear();
    }


    int m = 0;

    for (int i = 1; i <= n; i ++ ) if (cnt[i]) {
        p[++ m] = i;
        int now = p[m];
        if (dp[now].empty()) continue;
        s[now].resize(dp[now].size());
        for (int j = 0; j < dp[i].size(); j ++ ) {
            s[now][j] = dp[now][j];
            if (j) {
                s[now][j] += s[now][j - 1];
            }
        }
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
            assert(dp[now].size() == s[now].size());
            if (!dp[now].empty()) {
                ans += s[now][min((ll)s[now].size(), B) - 1];
            } 
        }
        cout << ans << "\n";
    }

   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; // cin >> T;
    while (T -- ) solve();
    return 0;
}