#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<pair<int, ll>, ll> dp;

int a[30], cnt;

ll calc(ll x) {
  if(x < 10) return x;
  ll ret = 1;
  while(x) {
    ret = ret * (x % 10);
    x /= 10;
  }
  return calc(ret);
}

ll dfs(int pos, ll sum, bool limit, bool lead) {
  if(pos == cnt) {
    if(lead) return 0;
    return calc(sum);
  }
  if(!lead && !limit && dp.count({pos, sum})) return dp[{pos, sum}];
  ll ret = 0;
  // ll &ret = dp[{pos, sum}];
  for(int i = 0; i <= (limit ? a[pos]: 9); i ++ ) {
    ret += dfs(pos + 1, sum * (i == 0 ? lead : i), limit && i == a[pos], lead && !i);
  }
  if(!lead && !limit) 
    dp[{pos, sum}] = ret;

  return ret;
}

int main() {
  ll n; cin >> n;
  while(n) {
    a[cnt ++ ] = n % 10;
    n /= 10;
  }
  reverse(a, a + cnt);
  cout << dfs(0, 1, true, true);

  return 0;
}