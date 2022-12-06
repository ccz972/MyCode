#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
  int n; cin >> n;
  string s; cin >> s;
  reverse(s.begin(), s.end());
  int cnt = 0;
  ll ans = 0;  
  for(int i = 0; i < n; i ++ ) {
    if(s[i] == '0') {
      ++ cnt;
    } else {
      if(cnt) {
        ans += n - i;
        cnt --;
      } else {
        cnt ++;
      }
    }
  }
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while(T -- ) solve();
  return 0;
}