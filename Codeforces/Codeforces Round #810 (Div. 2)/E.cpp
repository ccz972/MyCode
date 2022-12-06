/***************************************************

@File    : E.cpp
@Time    : 2022/07/25 23:15:12
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

constexpr int N = 2E5 + 10;
constexpr int p = 998244353;

int f[N][8][8];



int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.size();
  for(char &c: s) c -= '0';
  //000 001 010 011 100 101 110 111
  memset(f, -1, sizeof f);
  function<int(int, int, int)> dfs = [&] (int pos, int limit1, int limit2) -> int {
    if(pos >= n) return limit1 == 7;
    int &ret = f[pos][limit1][limit2];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0; i <= ((limit2 & 1) ? s[pos] : 1); i ++ ) {
      for(int j = 0; j <= ((limit2 >> 1 & 1) ? s[pos] : 1); j ++ ) {
        for(int k = 0; k <= ((limit2 >> 2 & 1) ? s[pos] : 1); k ++ ) {
          int now1 = limit1; //
          if((i ^ j) && (j ^ k)) now1 |= 1; //i != j && j != k  说明是 0 1 1 或者 1 0 0 
          if((i ^ k) && (j ^ k)) now1 |= 2; // 
          if((i ^ k) && (j ^ i)) now1 |= 4;
          int now2 = 0;
          if(i == s[pos] && (limit2 & 1)) now2 += 1;
          if(j == s[pos] && (limit2 >> 1 & 1)) now2 += 2; 
          if(k == s[pos] && (limit2 >> 2 & 1)) now2 += 4;
          ret += dfs(pos + 1, now1, now2);
          ret %= p;
          // ret += dfs(pos + 1, limit1 | (1 << ((i ^ j) && (j ^ k))) | (1 << ((i ^ k) && (j ^ k)) ?  | (1 << ((i ^ j) && (j ^ k)) | ))
        }
      }
    }
    // cout << pos << " " << limit1 << " " << limit2 << " " <<  ret << "\n";
    // exit(0);
    return ret;
  };

  cout << dfs(0, 0, 7);

  return 0;
}