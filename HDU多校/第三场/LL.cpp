#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<bitset>
 
#define int long long
#define x first
#define y second
#define ps push_back
#define endl '\n'
 
#define kd ios::sync_with_stdio(false);cin.tie();cout.tie(0);
using namespace std;
typedef pair<int,int>pi;
const int N=4e5+100,mod=998244353;
int lowbit(int x){return x&-x;}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
 
int hs1[N],hs2[N];
int a[N],b[N];
int d[2*N][2];
//  前 i 个中匹配成功同时 用了前 j 个 a 中的
int c[2*N];
 
void solve()
{
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                hs1[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
                cin>>b[i];
                hs2[b[i]]=i;
        }
        for(int i=1;i<=2*n;i++)
        {
                cin>>c[i];
        }
        for(int i=1;i<=2*n;i++)
        {
                d[i][0]=d[i][1]=0;
        }
        d[1][0]=(c[1]==a[1]);
        d[1][1]=(c[1]==b[1]);
        for(int i=2;i<=2*n;i++)
        {
                int t1=(hs1[c[i-1]]);
                int t2=(hs2[c[i-1]]);  
                //如果当前的位置和
                if(hs1[c[i-1]]==hs1[c[i]]-1)d[i][0]+=d[i-1][0],d[i][0]%=mod;
                if(hs1[c[i]]+hs2[c[i-1]]==i)d[i][0]+=d[i-1][1],d[i][0]%=mod;
               
                if(hs2[c[i-1]]==hs2[c[i]]-1)d[i][1]+=d[i-1][1],d[i][1]%=mod;
                if(hs2[c[i]]+hs1[c[i-1]]==i)d[i][1]+=d[i-1][0],d[i][1]%=mod;
        }
        cout<<(d[2*n][1]+d[2*n][0])%mod<<endl;
        // cout<<d[2*n][n]<<endl;
}
 
signed main()
{
        kd;
        int _;_=1;
        cin>>_;
        while(_--)solve();     
        return 0;
}