#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s[3];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node {
    int x, y;
    int flag;
};
constexpr int N = 5E5 + 10;
bool vis[5][N][4];
void solve() {
    int n, m, X, Y; n = 4;
    cin >> m >> X >> Y;
    for (int i = 0; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            for (int k = 0; k < 4; k ++ ) {
                vis[i][j][k] = false;
            }
        }
    }
    -- X, -- Y;
    // s[0] = string(m, ' ');
    // s[0][X] = 'I';
    cin >> s[1] >> s[2];
    queue<node> q;
    if (s[1][0] == 'L') {
        // vis[2][S] = true;
        // dfs (2, S, 0);
        // dfs (2, S, 2);
        q.push({1, X, 0});
        q.push({1, X, 2});
        vis[1][X][2] = true;
        vis[1][X][0] = true;
    } else {
        q.push({1, X, 1});
        vis[1][X][1] = true;
        // dfs (2, S, 1);
    }

    
    
    while (q.size()) {
        node t = q.front(); q.pop();
        auto [x, y, flag] = t;

        auto [nx, ny, nflag] = t;
  
        // cout << x << " " << y << " " << flag << "\n";
        nx += dx[flag], ny += dy[flag];
        // cout << nx << " " << ny << " " << flag << "\n\n";
        if (nx == 3) {
            if (ny == Y && flag == 1) {
                cout << "YES\n";
                return ;
            }
            continue;
        }
        
        if (nx <= 0 || nx >= n - 1 || ny < 0 || ny >= m) {
            continue;
        }       


        // cout << "> " << nx << " " << ny << " " << nflag << "\n";
        
        if (s[nx][ny] == 'I') {
            if (!vis[nx][ny][nflag]) {
                vis[nx][ny][nflag] = true;
                q.push({nx, ny, nflag});
            }
        }  else if (s[nx][ny] == 'L') {
            
            nflag = (flag + 1) % 4;
            
            if (!vis[nx][ny][nflag]) {
                vis[nx][ny][nflag] = true;
                q.push({nx, ny, nflag});
            }
            
            nflag = (flag + 3) % 4;
            
            if (!vis[nx][ny][nflag]) {
                vis[nx][ny][nflag] = true;
                q.push({nx, ny, nflag});
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while (T -- ) solve();
    return 0;
}