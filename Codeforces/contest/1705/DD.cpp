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
      if(i <= r) {
        s[i] = c;
      }
      if(s[i] == t[i]) continue;

      if(i + 1 <= r) {
        s[i + 1] = c;
      }

      if(s[i - 1] != s[i + 1]) {
        ++ ans;
        s[i] = t[i];
        continue;
      } 

      //s[i] != t[i];

      //case1: s[i] == s[i + 1]
      //0000001
      //找到i+1后面第一个和 s[i + 1] 不同的

      if(i + 1 == n - 1) {
        ans = -1;
        break;
      }

      if(s[i] == s[i + 1]) {
        int idx = nxt[i + 1 <= r ? r : i + 1][s[i + 1] ^ 1];
      
        if(idx >= n) {
          ans = -1;
          break;
        }
        //000 001
        // 12 345
        ans += idx - i;

        s[i] = t[i];

        r = idx;
        c = s[i + 1] ^ 1;

      } else {
        //0101011
        //0101111
        // if(s[i + 2])
        if(s[i + 2] == s[i]) {

        }
      }

      

      /*

      2 2 2 4 5
      最小值是2
      我们把所有的数字都变成2
      那么 5 就是 2 ^ (5 - 2) 个 2
      
      2 2 2 4 5 

      0 0 0 2 3


      */



    }




    

    
  }
  return 0;
}