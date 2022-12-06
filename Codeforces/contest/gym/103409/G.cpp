#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> last(n);
  int now = -1;
  for (int i = 0; i < n; i ++ ) if(s[i] == '1') {
    last[i] = now;
    now = i;
  }
  int a0 = 0, a1 = 0;
  int i = 0;
  if(s[0] == '1') {
    a0 = 0, a1 = 0;
  } else {
    while(s[i] != '1') i ++;
    //
    a0 = i; a1 = i + 1;
    i ++;
  }
  for ( ; i < n; i ++ ) if(s[i] == '1') {
    int j = i;
    while(j + 1 < n && s[j + 1] == '1') {
      ++ j;
    }
    int len = i - last[i] - 1;
    if(j == i) {
      int b0 = min(max(a0, len == 1 ? 1 : 1 + len / 2), max(a1, (len + 1) / 2));
      int b1 = min(max(a0, 1 + (len + 1) / 2), max(a1, 1 + len / 2));
      a0 = b0, a1 = b1;
    } else {
      int b0 = min(max(a0, len == 1 ? 1 : 1 + len / 2), max(a1, (len + 1) / 2));
      int b1 = min(max(a0, len == 1 ? 1 : 1 + len / 2), max(a1, (len + 1) / 2));
      a0 = b0, a1 = b1;
    }
    i = j;
  }
  int ans;
  if(s.back() != '1') {
    ans = min(max(a0, 1 + n - 1 - now), max(a1, n - 1 - now));
  } else {
    ans = min(a0, a1);
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