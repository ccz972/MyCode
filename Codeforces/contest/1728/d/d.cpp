/* Generated by powerful Codeforces Tool
 * Author: SmartNanfeng
 * Time: 2022-09-08 22:35:01
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2010;

int dp[N][N];

string s;

int dfs(int l, int r) {
  //l,r-2
  if (dp[l][r] != -2) return dp[l][r];
  if (r - l == 1) {
    if (s[l] == s[r]) dp[l][r] = 0;
    else dp[l][r] = 1;
    return dp[l][r];
  }
  // Alice select l
  // Bob select r
  int state1 = dfs(l + 1, r - 1);
  int flag1 = -2;
  if (state1 == -1) {
    flag1 = -1;
  } else if(state1 == 0) {
    if (s[l] < s[r]) {
      flag1 = 1;
    } else if(s[l] == s[r]) {
      flag1 = 0;
    } else {
      flag1 = -1;
    }
  } else {
    flag1 = 1;
  }

  // Bob select l + 1
  int state2 = dfs(l + 2, r);
  int flag2 = -2;
  if (state2 == -1) {
    flag2 = -1;
  } else if(state2 == 0) {
    if (s[l] < s[l + 1]) {
      flag2 = 1;
    } else if(s[l] == s[l + 1]) {
      flag2 = 0;
    } else {
      flag2 = -1;
    }
  } else {
    flag2 = 1;
  }
  
  if (flag1 == flag2 && flag1 == 1) {
    dp[l][r] = 1;
    return 1;
  }


  // Alice select r
  // Bob select r - 1
  int state3 = dfs(l, r - 2);
  int flag3 = -2;
  if (state3 == -1) {
    flag3 = -1;
  } else if(state3 == 0) {
    if (s[r] < s[r - 1]) {
      flag3 = 1;
    } else if(s[r] == s[r - 1]) {
      flag3 = 0;
    } else {
      flag3 = -1;
    }
  } else {
    flag3 = 1;
  }

  // Bob select l
  int state4 = dfs(l + 1, r - 1);
  int flag4 = -2;
  if (state4 == -1) {
    flag4 = -1;
  } else if(state4 == 0) {
    if (s[r] < s[l]) {
      flag4 = 1;
    } else if(s[r] == s[l]) {
      flag4 = 0;
    } else {
      flag4 = -1;
    }
  } else {
    flag4 = 1;
  }

  if (flag3 == flag4 && flag4 == 1) {
    dp[l][r] = 1;
    return 1;
  }

  if ((flag1 == -1 || flag2 == -1) && (flag3 == -1 || flag4 == -1)) {
    dp[l][r] = -1;
    return -1;
  }

  dp[l][r] = 0;
  return 0;
  
}

void solve2() {
  cin >> s;
  int n = s.size();
  s = " " + s;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= n; j ++ ) {
      dp[i][j] = -2;
    }
  }
  auto t = dfs(1, n);
  if (t == 1) {
    cout << "Alice\n";
  } else if (t == -1) {
    cout << "Bob\n";
  } else {
    cout << "Draw\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1; cin >> T;
  while (T --) solve2();
  return 0;
}

/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
