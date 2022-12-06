#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1E6 + 10, INF = 0x3f3f3f3f;
int v[3] = {7,31,365};
int dp[N];

int main()
{
    int T;scanf("%d",&T);
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for(int i=0;i<3;i++)
        for(int j=v[i];j<N;j++)
            if(dp[j-v[i]]!=INF)
                dp[j] = min(dp[j],dp[j-v[i]]+1);
    while(T--)
    {
        LL n,ans;scanf("%lld",&n);
        LL cnt = n/365;
        n%=365;
        ans = INF;
        for(int i = 0; i <= min(cnt, 2000ll); i ++ ) {
          ans = min(ans, cnt - i + dp[n + i * 365]);
        }
        // printf("%/lld %lld\n", ans, INF / 2);
        if(ans <= INF) printf("%lld\n",ans);
        else printf("-1\n");
    }
    return 0;
}
