#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node {
    int x, y;
    int flag;
};
constexpr int N = 5E5 + 10;
// bool vis[5][N][4];
char s[5][N];
int S, T;
int n, m;
bool ans;
bool vis[5][N][4];

void solve() {
    n = 4;
    // cin >> m >> S >> T;
    scanf("%d%d%d", &m, &S, &T);
    assert(m <= 100000);
    assert(S <= m && T <= m);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            s[i][j] = ' ';
            for (int k = 0; k < 4; k ++ )
                vis[i][j][k] = false;
        }
    }

    

    scanf("%s %s", s[2] + 1, s[3] + 1);
    vis[1][S][1] = true;
    if (s[2][1] == 'L')
        vis[2][S][0] = true;
    else 
        vis[2][S][1] = true;
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 2; j <= 3; j ++ ) {
            for (int k = 0; k < )
        }
    }
    
    puts(ans ? "YES" : "NO");
}

int main() {
    int T = 1; scanf("%d", &T); //cin >> T;
    while (T -- ) solve();
    return 0;
}