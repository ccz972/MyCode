#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node {
    int x, y;
    int flag;
};
constexpr int N = 1E6 + 10;
bool vis[5][N];
char s[5][N];
int S, T;
int n, m;
bool ans;
void dfs (int x, int y, int flag) {
    if (ans) return ;
    x += dx[flag], y += dy[flag];
    if (vis[x][y]) return ;
    if (x == 4) {
        if (y == T && flag == 1) {
            ans = true;
        }
        return ;
    }
    if (x <= 1 || x >= n) return ;
    if (y < 1 || y > m) return ;
    
    if (s[x][y] == 'I') {
        vis[x][y] = true;
        dfs (x, y, flag);
    } else if (s[x][y] == 'L') {
        vis[x][y] = true;
        dfs (x, y, (flag + 1) % 4);
        dfs (x, y, (flag + 3) % 4);
    }
    vis[x][y] = false;
    
}

void solve() {
    n = 4;
    scanf("%d%d%d", &m, &S, &T);
    assert(m <= 100000);
    assert(S <= m && T <= m);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            s[i][j] = ' ';
            vis[i][j] = false;
        }
    }
    scanf("%s %s", s[2] + 1, s[3] + 1);    
    ans = false;
    dfs(1, S, 1);
    puts(ans ? "YES" : "NO");
}

int main() {
    int T = 1; scanf("%d", &T); //cin >> T;
    while (T -- ) solve();
    return 0;
}