#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;

int f[N], p[N];
bool vis[N];
int is[N];
vector<int> mp[N];
int cnt[N];
vector<int> son[N];
vector<int> a;

void find(int u) {
    a.emplace_back(u);
    is[u] = 1;
    int F = f[u];
    
    while (F != u) {
        a.emplace_back(F);
        is[F] = 1;
        F = f[F];
    }
}
int start = 0;
void dfs(int u) {
    ++ start;
    if (start >= 20) return ;
    cout << "u = " << u << "\n";
    if (vis[u]) {
        if (!is[u]) {
            find(u);
        }
        return ;
    }
    vis[u] = true;
    dfs(f[u]);
}

int sum;

void dfs(int u, int fa) {
    for (int &v: son[u]) if (v != fa) {
        sum ++;
        dfs(v, u);
    }
}

void solve() {
    int n; cin >> n;    
    for (int i = 1; i <= n; i ++ ) {
        cin >> f[i];
        son[f[i]].emplace_back(i);
    }

    for (int i = 1; i <= n; i ++ ) if (!vis[i]) {
        dfs(i);
        // cout << i;
        // cout << a.size() << "\n";
        if (a.empty()) continue;
        // return ;
        // return ;
        cnt[(int)a.size()] ++;
        
        for (int j = 0; j < a.size(); j ++ ) {
            sum = 0;
            // dfs(a[j], a[j]);
            mp[(int)a.size()].emplace_back(sum);
            cout << "sum = " << sum << "\n";
        }        
        
        a.clear();
    }  

    // int m = 0;
    // for (int i = 1; i <= n; i ++ ) if (cnt[i]) {
    //     p[++ m] = i;
    // }
    // for (int i = 1; i <= m; i ++ ) {
    //     cout << "i : " << cnt[p[i]] << "\n";
    //     for (int x: mp[p[i]]) {
    //         cout << x << " ";
    //     }
    //     cout << "\n\n";
    // }
    // int q; cin >> q;
    // while (q -- ) {
    //     long long a, b; cin >> a >> b;
    // }



    // for (auto &[k, v]: mp) {
    //     sort(v.begin(), v.end());
    // }
    // for (auto [k, v]: mp) {
    //     cout << k << ": ";
    //     for (int &t: v) cout << t << " ";
    //     cout << "\n";
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; // cin >> T;
    while (T -- ) solve();
    return 0;
}