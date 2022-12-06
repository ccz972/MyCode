#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int N = 1E5 + 10;

ll n;
ll a[N], b[N];
ll f[N], g[N];
bool st[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> a[i];
  for(int j = 1; j <= n; j ++ ) cin >> b[j];

  ll ans =  a[1];
  
  for(ll i = 2; i <= n; i ++ ) if(!st[i]) {
    int m = 0;
    for(ll j = i; j <= n; j *= i) {
      f[m] = a[j], g[m] = b[j];
      m ++;
      st[j] = true;
    }   

    ll ret = 0; 
    for(int j = 0; j < 1 << m; j ++ ) {
      ll now = 0;  ///int cnt = 0;
      for(int k = 0; k < m; k ++ ) if(j >> k & 1) {
        now += f[k];
        for(int l = k + 1; l < m; l ++ ) if(j >> l & 1) {
          if( (l + 1) % (k + 1) == 0) {
            now -= g[l];
          }
        }
      }
      ret = max(ret, now);
    }
    // if(ret >= 0)
    ans += ret;
  }

  cout << ans << "\n";

  

  return 0;
}