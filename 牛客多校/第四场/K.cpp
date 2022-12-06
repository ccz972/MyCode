/***************************************************

@File    : K.cpp
@Time    : 2022/07/30 12:06:53
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  cin.tie(nullptr)->sync_with_stdio(false);
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// constexpr int N = 1E6 + 10;

// int nxt[10][N];
int ANS;
void dfs(int now, int ed, int cnt, int n) {
  // debug(now, ed, cnt, n, ANS);
  // debug(now);
  if(cnt >= ANS || cnt >= 6) return ;
  if(now == ed) {
    chkmin(ANS, cnt);
    return ;
  }
  for(int i = 0; i < 10; i ++ ) {
    // if((now * 10 + i) % n != now)
    // debug(i);
      dfs((now * 10 + i) % n, ed, cnt + 1, n);
  }
}

int got(int now, int nxt, int n) {
  //now -> nxt    | % n
  // if(now == nxt) return 0;
  ANS = INT_MAX;
  dfs(now, nxt, 0, n);
  return ANS;
}

void solve() {
  cout << "FUCHK\n";
  // ANS = INT_MAX;
  // dfs(1, 2, 0, 100);
  // cout << ANS << "\n";
  int CT = 0;
  // vector<int> a;
  // for(int n = 1; n <= 400; n ++ ) 
  {    
    int n = 100000;
    int now = 0, ans = 0;
    for(int i = 1; i <= n; i ++ ) {
      // ans += got(now, i % n, n);
      chkmax(CT, got(now, i % n, n));
      // cout << ans;
      now = i;
    }
    
    // a.push_back(ans);
    // cout << ans << "\n";
    // if(n == 2) exit(0) ;
  }
  cout << CT << "\n";
  // cout << a[0] << " ";
  // for(int i = 1; i < a.size(); i ++ ) {
  //   cout << a[i] - a[i - 1] << " ";
  // }

}
int main() {
#ifndef ONLINE_JUDGE
  freopen("K.txt","w",  stdout);
#else
  cin.tie(nullptr)->sync_with_stdio(false);
#endif

  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}

