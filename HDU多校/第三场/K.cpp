#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>P[i].x>>P[i].y>>P[i].w;
    sort(P+1,P+n+1);
    a[n+1] = b[n+1] = c[n+1] = d[n+1] = -INF;
    for(int i=n;i;i--)
    {
        a[i] = max(a[i+1],P[i].x+P[i].y);
        b[i] = max(b[i+1],P[i].x-P[i].y);
        c[i] = max(c[i+1],-P[i].x+P[i].y);
        d[i] = max(d[i+1],-P[i].x-P[i].y);
    }
    while(q--)
    {
        int x,y;cin>>x>>y;
        int l = 1,r = n,ans = 0;
        while(l<r)
        {
            int mid = l + r + 1 >> 1;
            int res = max(max(-x-y+a[mid],-x+y+b[mid]),max(x-y+c[mid],x+y+d[mid]));
            if(P[mid].w<res) 
            {
                ans = max(ans,P[mid].w);
                l = mid;
            }
            else 
            {
                r = mid - 1;
                ans = max(ans,res);
            }
        }
        int res = max(max(-x-y+a[l],-x+y+b[l]),max(x-y+c[l],x+y+d[l]));
        if(P[l].w<res) ans = max(ans,P[l].w);
        else ans = max(ans,res);
        cout<<ans<<"\n";
    }
} 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
