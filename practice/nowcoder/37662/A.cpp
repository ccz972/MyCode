/***************************************************

@File    : A.cpp
@Time    : 2022/07/14 22:58:52
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

#include <bits/stdc++.h>
using namespace std;

#define int128 __int128

inline __int128 read() {
  __int128 x = 0, f = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9') {
    if(ch == '-') f = -1;
    ch = getchar();
  }
  while(ch >= '0' && ch <= '9'){
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

inline void print(__int128 x) { 
  if(x < 0){
    putchar('-');
    x = -x;
  }
  if(x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}



int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i ++ ) {
    cin >> a[i] >> b[i];
    assert(a[i] >= 1);
    assert(b[i] >= 1);
  }

  auto chk = [&] (int128 x) {
    int128 now = 0;
    for(int i = 0; i < n; i ++ ) {
      now += 1ll * (x / b[i] + 1) * a[i];
    }
    return now >= (int128)m;
  };

  int128 l = 0, r = 2E18;
  while(l < r) {
    int128 mid = (l + r) / 2;
    if(chk(mid)) r = mid;
    else l = mid + 1;
  }
  print(l);
  // cout << l << "\n";

  return 0;
}