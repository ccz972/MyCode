#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define all(a) a.begin(), a.end()
#define chkmax(a, b) a = (a >= b ? a : b)
#define pow2(a) ((a) * (a))
constexpr int N = 1E7 + 10;

ll f[N];
int p[N],pe[N];
int pri[N],cnt;
bool st[N];

void solve() {
  int n;cin>>n;
  p[1] = pe[1] = 1;
  for(int i=2;i<=n;i++)
  {
    if(!st[i]) pri[++cnt] = i,p[i] = i,pe[i] = i;
    for(int j=1;j<=cnt&&pri[j]*i<=n;j++)
    {
      st[pri[j]*i] = 1;
      p[pri[j]*i] = pri[j];
      if(i%pri[j]==0)
      {
        pe[pri[j]*i] = pe[i]*pri[j];
        break;
      }
      pe[pri[j]*i] = pri[j];
    }
  }
  // for(int i=1;i<=n;i++) cout<<i<<' '<<p[i]<<' '<<pe[i]<<'\n';
  // cout<<'\n';
  ll ans = 1;
  f[1] = (ll)1;
  for(int i=2;i<=n;i++){
    if(i==pe[i])
    {
      if(i==p[i])
      {
        f[i] = (ll)1;
      }
      else f[i] = (ll)p[i]*f[i/p[i]/p[i]];
    }
    else 
    {
      f[i] = (ll)i/pe[i]*f[pe[i]];
    }
    // cout<<i<<" "<<f[i]<<endl;
    ans += f[i];
  }
  cout<<ans<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- ) {
    solve();
  }
  return 0;
}