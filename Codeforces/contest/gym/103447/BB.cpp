#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e5 + 10, M = 201;

int n;
int a[N];
// int f[N][]
int nxt[N];
int f[M];
int dp[N];

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  int ans = 0;
  for(int x = 2; x <= 200; x ++ ) {

    memset(f, 0, sizeof f);
    memset(dp, 0, sizeof dp);
    memset(nxt, 0, sizeof nxt);

    for(int i = 1; i <= n; i ++ ) if(a[i] < x) {
      if(!f[a[i]]) {
        f[a[i]] = i;
      }
      if(f[x - a[i]]) {
        nxt[f[x - a[i]]] = i;
        nxt[i] = f[x - a[i]];
        
        f[x - a[i]] = 0;
      }
    }

    for(int i = 1; i <= n; i ++ ) {
      dp[i] = dp[i - 1];
      if(nxt[i] < i) {
        dp[i] = max(dp[i], dp[nxt[i] - 1] + 1); 
      }
    }

    ans = max(ans, dp[n] * 2);

  }
  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();

  return 0;
}