#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;
constexpr int MOD = 1E9 + 7;


ll ksm(ll a, ll b, ll ret = 1) {
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    b >>= 1;
    a = a * a % MOD;
  }
  return ret;
}

void solve() {
  string s; cin >> s;
  ll c; cin >> c;
  if (c == 0) {
    cout << "1\n";
    return ;
  } //0 1 2 3 4 5 6
    //1 3 3 9 3 9 9
    //
  ll ans = 0;
  ll cnt = 1;
  int n = s.size();
  for (int i = 0; i < n; i ++ ) if (s[i] == '1') {

    ll ret = ((cnt * ((ksm(1 + c, n - i - 1) - 1 + MOD) % MOD) % MOD) + (((cnt * c) % MOD))) % MOD;
    ans += ret; ans %= MOD;
    cnt *= c; cnt %= MOD;
    // cout << ret << "\n";
  }
  //00 01 10 11
  //9 + 3 + 3

  //3 + 9 + 9
  //100 101 
  //110
  ans = ans + 1; ans %= MOD;
  ans = (ans + MOD) % MOD; 
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}