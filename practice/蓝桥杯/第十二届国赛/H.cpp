#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

ll n;
int k, cnt;
int a[52]; 

ll dp[70][52][2][2];

ll dfs (int pos, int cntd, bool limit, bool lead) {
  if(pos == cnt) {
    return (ll)(cntd == k);
  }
  ll &ret = dp[pos][cntd][limit][lead];
  if(~ret) return ret;
  ret = 0;
  for(int i = 0; i <= (limit ? a[pos] : 1); i ++ ) {
    ret += dfs(pos + 1, cntd + i, limit && (i == a[pos]), lead && !i);
  }
  return ret;
}

void solve() {
  cin >> n >> k;
  while(n) {
    a[cnt ++ ] = (n & 1);
    n >>= 1;
  }
  reverse(a, a + cnt);
  memset(dp, -1, sizeof dp);
  cout << dfs(0, 0, true, true);


}

int main() {
  solve();
  return 0;
}