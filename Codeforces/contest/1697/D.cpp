#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<string>
#include<random>
#include<iomanip>
#define yes puts("yes");
#define inf 0x3f3f3f3f
#define ll long long
#define linf 0x3f3f3f3f3f3f3f3f
#define ull unsigned long long
#define endl '\n'
#define int long long
#define rep(i,a,n) for(int i = a;i <= n;i++)
#define per(i,n,a) for(int i = n;i >= a;i--)
using namespace std;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
typedef pair<int,int> PII;
const int MAXN =10 + 2e5 ,mod=1e9 + 7;

void solve()
{    
    int n; cin >> n;
    string s,t; cin >> s >> t;
    vector<int> cs(3),ct(3);
    rep(i,0,n - 1) {
        cs[s[i] - 'a'] ++;
        ct[t[i] - 'a'] ++;
    }
    rep(i,0,2) if(cs[i] != ct[i]) {
        cout << "NO\n";
        return;
    }
    // ab -> ba   bc->cb  abbb-> bbba bccc->bccc  b bbbccc
    int i = 0,j = 0;
    bool ok = 1;
    for(;i < n;i ++) {
        if(s[i] == t[i]) continue;
        if(s[i] == 'a') {
            if(t[i] == 'c') ok = 0;
            else {// t[i] == b
                bool haveb = 0;
                int k = i + 1;
                while(k < n && s[k] == 'a') k ++;
                // aaax
                if(k < n && s[k] == 'b') haveb = 1;
                if(!haveb) ok = 0;
                else {
                    // aaab -> baaa
                    swap(s[k],s[i]);
                }
            }
        }else if(s[i] == 'b') {
            if(t[i] == 'a') ok = 0;
            else {
                bool havec = 0;
                int k = i + 1;
                while(k < n && s[k] == 'b') k ++;
                // aaax
                if(k < n && s[k] == 'c') havec = 1;
                if(!havec) ok = 0;
                else {
                    // bc -> cb
                    swap(s[k],s[i]);
                }
            }
        }else {
            // c | a or b
            ok = 0;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T;cin>>T;
    while(T--)
        solve();

    return 0;
}