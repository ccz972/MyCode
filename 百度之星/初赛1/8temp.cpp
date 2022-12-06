#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<functional>
#include<cassert>
#include<random>
#include<iomanip>
#define yes puts("yes");
#define inf 0x3f3f3f3f
#define ll long long
#define linf 0x3f3f3f3f3f3f3f3fll
#define ull unsigned long long
#define endl '\n'
// #define int long long
#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
using PII = pair<int,int>;
const int MAXN =10 + 1e4 ,mod=1e9 + 7;
int n,m;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<PII> q;
void solve()
{    
    cin >> n >> m;
    memset(f,0x3f,sizeof f);
    rep(i,1,n) rep(j,1,m) {
        cin >> a[i][j];
        if(a[i][j] == 0) {
            f[i][j] = 0;
            q.push({i,j});
        }
    }
    while(q.size()) {
        PII p = q.front(); q.pop();
        for(int i = 0;i < 4;i += 1) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx <= 0 or nx > n or ny <= 0 or ny > m) continue;
            if(a[nx][ny] < a[p.first][p.second]) continue;
            if(f[nx][ny] != inf) continue;
            f[nx][ny] = min(f[nx][ny], f[p.first][p.second] + 1);
            q.push({nx,ny});
        }
    }
    for(int i = 1;i <= n;i += 1) {
        for(int j = 1;j <= m;j += 1)
            cout << (f[i][j] == inf ? -1 : f[i][j]) << ' ';
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    //int T;cin>>T;
    //while(T--)
        solve();

    return 0;
}
