#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

int main()
{
    int T;scanf("%d",&T)    ;
    while(T--)
    {
        LL p,q;scanf("%lld%lld",&p,&q);
        LL d = __gcd(p,q);
        int Q = q,P = p;
        vector<int> A,B;
        while(P)
        {
            A.push_back(P%10);
            P/=10;
        }
        while(Q)
        {
            B.push_back(Q%10);
            Q/=10;
        }

        int len1 = A.size(),len2 = B.size();

        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());

        LL ans1 = p,ans2 = q;

        q/=d,p/=d;

        for(int i=1;i<1<<len1;i++)
        {
            LL res = 0;
            vector<int> cnt(10);
            for(int j=0;j<len1;j++)
                if(i>>j&1) res = res*10 + A[j];
				
                else cnt[A[j]]++;

            if(!res||res%p) continue;

            LL t = res/p*q,t1 = t;

            for(int j=len2-1;j>=0;j--)
                if(t1%10==B[j]) t1/=10;
                else cnt[B[j]] --;
			
            if(t1) continue;

            bool f = 0;
            for(int j=0;j<10;j++)
                if(cnt[j]){
                    f=1;
                    break;
                }
            if(f) continue;
            if(res<ans1) ans1 = res,ans2 = t;
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}