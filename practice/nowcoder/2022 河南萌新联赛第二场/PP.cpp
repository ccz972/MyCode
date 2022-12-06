#include<bitsdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

LL s[N];
int tr[N];
vector<LL> a;
int n;

int get(LL x)
{
    return lower_bound(a.begin(),a.end(),x) - a.begin() + 1;
}

void add(int x)
{
    while(x<=n)
    {
        tr[x] ++;
        x += x & -x;
    }
}

int sum(int x)
{
    int res = 0;
    while(x)
    {
        res += tr[x];
        x -= x & -x;
    }
    return res;
}

int main()
{
    LL x,y;
    cin>>n>>x>>y;
    LL ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
//         if(s[i]<=x+y) ans++;
        s[i] += s[i-1] - y;
//         cout<<s[i]<<" ";
        a.push_back(s[i]+x);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    for(int i=1;i<=n;i++)
    {
        int t;
        if(s[i]<=x) ans++;
        t = get(s[i]);
        int m = sum(n) - sum(t-1);
        ans += m;
        t = get(s[i]+x);
        add(t);
    }
    cout<<ans<<"\n";
    return 0;
}
