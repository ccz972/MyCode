#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> e(n);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    
    std::vector<int> siz[3];
    for (int i = 0; i < 3; ++i) siz[i].resize(n);
    std::vector<int> len(n);
    
    int m[3];
    for (int i = 0; i < 3; ++i) {
        std::cin >> m[i];
        for (int j = 0; j < m[i]; ++j) {
            int u;
            std::cin >> u;
            --u;
            siz[i][u]++;
        }
    }
    
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (auto [v, w] : e[u]) {
            if (v == p) continue;
            len[v] = w;
            dfs(v, u);
            for (int i = 0; i < 3; ++i) siz[i][u] += siz[i][v];
        }
    };
    dfs(0, -1);
    
    double ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            int64_t res = 0;
            for (int u = 1; u < n; ++u) res += int64_t(siz[i][u]) * (m[j] - siz[j][u]) * len[u];
            ans += double(res) / m[i] / m[j];
        }
    }
    
    std::cout << std::fixed << std::setprecision(5) << ans / 2 << "\n";
    
    return 0;
}