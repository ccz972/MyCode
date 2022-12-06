#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i(a);i<=b;++i)
const int N=1E5+10,M=2.6E7;
int n,m,a[N],p[M*2],*C=p+M;
main(){cin>>n;F(i,1,n)cin>>a[i];F(i,-200,200){F(j,1,n)m=max(m,++C[a[j]+i*j]);F(j,1,n)C[a[j]+i*j]=0;}
  F(i,1,n){F(j,i+1,min(n,i+499))if((a[j]-a[i])%(j-i)==0)m=max(m,++C[(a[j]-a[i])/(j-i)]+1);F(j,i+1,min(n,i+499))C[(a[j]-a[i])/(j - i)]=0;}
  return cout<<n-m, 0;
}