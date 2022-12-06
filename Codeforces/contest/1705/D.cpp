/***************************************************

@File    : D.cpp
@Time    : 2022/07/15 22:14:59
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) {
    int n; cin >> n;
    string S; cin >> S;
    vector<int> s(n), t(n);
    for(int i = 0; i < n; i ++ ) {
      s[i] = S[i] - '0';
    }
    cin >> S;
    for(int i = 0; i < n; i ++ ) {
      t[i] = S[i] - '0';
    }

    vector<array<int, 2> > nxt(n);
    vector<int> now{n, n};
    for(int i = n - 1; i >= 0; i --  ) {
      nxt[i][0] = now[0];
      nxt[i][1] = now[1];      
      now[s[i]] = i;
    }

    if(s == t) {
      cout << "0\n";
      continue;
    }

    if(s[0] != t[0] || s.back() != t.back()) {
      cout << "-1\n";
      continue;
    }
    ll ans = 0;
    int r = -1, c = 2;
    for(int i = 1; i < n - 1; i ++ ) {
      if(i < r) {
        s[i] = c;
      }

      if(s[i] == t[i]) continue;

      if(i + 1 < r) {
        s[i + 1] = c;
      }

      if(s[i + 1] != s[i - 1]) {
        ++ ans;
        s[i] = t[i];
        continue;
      }
      // int idx;
      // if(c == (s[i] ^ 1)) {
        
      // }
      int idx = nxt[(r == -1 || r <= i) ? i + 1 : r][i + 1 > r ? (s[i + 1] ^ 1) : (c ^ 1)];
      debug(i, idx);
      if(idx >= n) {
        ans = -1;
        break;
      }
      s[i] = t[i];
      ans += idx - i;
      r = idx;
      c = s[i + 1] ^ 1;
      // debug(r, c);
    }
    // cout << "-----\n";
    // for(int i = 0; i < n; i ++ ) {
    //   cout << s[i];
    // }
    // cout << "\n";
    // for(int i = 0; i < n; i ++ ) {
    //   cout << t[i];
    // }
    // cout << "\n";
    cout << ans << "\n";
    // cout << "-----\n";
    // bool flag = true;
    // for(int i = 0; i < n; i ++ ) {
    //   if(s[i] != s[i & 1]) {
    //     flag = false;
    //   }
    // }

    // //xyxyxyxyxyx
    // if(flag) {
    //   cout << "-1\n";
    //   continue;
    // }



    

    
  }
  return 0;
}