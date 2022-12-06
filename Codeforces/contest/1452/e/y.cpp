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
#define int long long
#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
using PII = array<int,2>;
const int MAXN =10 + 2e5 ,mod=1e9 + 7;

void solve()
{    
    int n,m,h,q; cin >> n >> h >> m >> q;
    vector<array<int,3>> a(n * 2 + q);
    for(int i = 0;i < 2 * n;i += 2) {
        int x,y,z,w; cin >> x >> y >> z >> w;
        int t1 = x * m + y;
        int t2 = z * m + w;
        a[i] = {t1,1,-1};
        a[i + 1] = {t2,-1,-1};
    }
    for(int i = 2 * n;i < 2 * n + q;i ++) {
        int x,y; cin >> x >> y;
        int t = x * m + y;
        a[i] = {t,0,i - 2 * n};
    }

    sort(a.begin(),a.end(),[&](auto A,auto B) {
        if(A[0] != B[0])
            return A[0] < B[0];
        return A[1] > B[1];
    });

    vector<int> ans(q);

    int now = 0;
    for(int i = 0;i < a.size();i += 1) {
        now += a[i][1];
        if(a[i][1] == 0)
            ans[a[i][2]] = now;
        
    }

    for(int i = 0;i < q;i += 1)
        cout << (ans[i] ? "No" : "Yes") << endl;
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    //int T;cin>>T;
    //while(T--)
        solve();

    return 0;
}
