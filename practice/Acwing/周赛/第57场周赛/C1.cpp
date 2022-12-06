#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x -= 100;
  vector<int> s(n + 1);
  for(int i = 1; i <= n; i ++ ) {
    s[i] = s[i - 1] + a[i - 1];
  }
  // stack<int> stk;
  vector<int> stk;
  int ans = *max_element(a.begin(), a.end()) > 0;
  for(int i = 1; i <= n; i ++ ) {
    cout << s[i] << " \n"[i == n];
  }
  for(int i = 1; i <= n; i ++ ) {
    if(!stk.empty() && s[stk.back()] > s[i]) {
      stk.push_back(i);
    } else if(!stk.empty() && s[stk.back()] < s[i]) {
      int l = 0, r = (int)stk.size() - 1;
      while(l < r) {
        //7 6 5 4 3 
        int mid = (l + r) / 2;
        if(s[stk[mid]] < s[i]) r = mid;
        else l = mid + 1;
      }
      if(s[stk[l]] < s[i]) {
        ans = max(ans, i - stk[l]);
      } 
    } else if(stk.empty()) {
      stk.push_back(i);
    }
    
  }
  cout << ans << "\n";
  return 0;
}