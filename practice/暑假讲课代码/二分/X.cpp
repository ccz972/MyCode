#include<bits/stdc++.h>
using namespace std;
//#define double long double
#define endl '\n'
int m;
struct noi
{
    int J,F;
    double v;
}e[1005];
bool cmp(noi a,noi b){
    return a.v>b.v;
}
int n;
int main()
{
    //ios::sync_with_stdio(0);
    while(cin>>m>>n){
        if(m==-1) break;
        for(int i=1;i<=n;i++){
            cin>>e[i].J>>e[i].F;
            e[i].v=1.0 * e[i].J/e[i].F;
        }
        sort(e+1,e+n+1,cmp);
        double ans=0;
        for(int i=1;i<=n;i++){
            if(m >= e[i].F) {m-=e[i].F;ans+=e[i].J;}
            else {ans+=(1.0 * e[i].J*m/e[i].F);break;} 
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}
