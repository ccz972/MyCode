#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E6 + 10;

int n, tt, stk[N];
ll s[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> s[i];
    s[i] = s[i] - 100 + s[i - 1];
  }
  int ans = 0;
  stk[tt] = 0;
  for(int i = 1; i <= n; i ++ ) {
    if(s[stk[tt]] > s[i]) {
      stk[++ tt] = i;
    } else if(s[stk[tt]] < s[i]) {
      int l = 0, r = tt;
      while(l < r) {
        //7 6 4 3
        int mid = (l + r) / 2;
        if(s[stk[mid]] < s[i]) r = mid;
        else l = mid + 1;
      }
      if(s[stk[l]] < s[i]) {
        ans = max(ans, i - stk[l]);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}