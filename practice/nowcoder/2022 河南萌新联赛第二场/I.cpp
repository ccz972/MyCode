/***************************************************

@File    : I.cpp
@Time    : 2022/07/17 14:01:16
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 12;

int cnt, a[N];
ll dp[N][N][22][2][2];

ll dfs(int pos, int len, int sum, bool lead, bool limit) {
  if(pos == cnt) {
    // if(lead) return 0;
    // if(len && (sum % len == 0) && (sum / len == 2))
    //   debug(pos, len, sum, lead, limit);
    return  len && (sum % len == 0) && (sum / len == 2);
  }
  ll &ret = dp[pos][len][sum][lead][limit];
  if(~ret) return ret;
  ret = 0;
  for(int i = 0; i <= (limit ? a[pos] : 9); i ++ ) {
    if(lead) {
      if(!i) ret += dfs(pos + 1, 0, 0, lead, limit && (i == a[pos]));
      else ret += dfs(pos + 1, 1, i, !lead, limit && (i == a[pos]));
    } else {
      ret += dfs(pos + 1, len + 1, (sum + i >= 20 ? 21 : sum + i), false, limit && (i == a[pos]));
    }
  }
  return ret;
}

ll solve(ll x) {
  cnt = 0;
  while(x) {
    a[cnt ++] = x % 10;
    x /= 10;
  }
  reverse(a, a + cnt);
  memset(dp, -1, sizeof dp);
  return dfs(0, 0, 0, true, true);
}

ll baoli(ll x) {
  ll cnt = 0;
  for(ll i = 1; i <= x; i ++ ) {
    ll sum = 0, res = i;
    while(res) {
      sum += res % 10;
      res /= 10;
    }
    if(sum % (int)(to_string(i).size()) == 0 && sum / (int)(to_string(i).size()) == 2) {
      ++ cnt;
    }
  }
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // ll n; cin >> n; cout << solve(n);
  for(int i = 1; i <= 100; i ++ ) {
    cout << i << " " << solve(i) << " " << baoli(i) << "\n";
    // if(solve(i) != baoli(i)) {  
    //   cout << i << "\n";
    //   break;
    // }
  }
  

  return 0;
}