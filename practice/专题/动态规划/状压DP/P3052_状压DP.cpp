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

constexpr int N = 20;
constexpr int M = 1 << N;
int a[N];
int f[M], sz[M];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, w; cin >> n >> w;
  memset(f, 127, sizeof f);
  f[0] = 1;
  sz[0] = w;
  for(int i = 0; i < n; i ++ ) cin >> a[i];
  for(int i = 0; i < 1 << n; i ++ ) {
    for(int j = 0; j < n; j ++ ) if(not (i >> j & 1)) { //只有 j 不在 i 中，才进行状态转移
      if(sz[i] >= a[j]) { // 如果 i 这个状态装得下 j ，那么我们就不要再开一个
        if(f[i] < f[i | (1 << j)]) { //如果 f[i] < f[i | (1 << j)] 那么我们一定要从 i 转移过来
          f[i | (1 << j)] = f[i];
          sz[i | (1 << j)] = sz[i] - a[j];
        } else if(f[i] == f[i | 1 << j]) { //如果 f[i] == f[i | (1 << j)] 那么我们判断 sz[i | (1 << j)] 和 sz[i] - a[j] 的大小
          sz[i | (1 << j)] = max(sz[i | 1 << j], sz[i] - a[j]);
        }
      } else { //装不下 同理
        if(f[i] + 1 < f[i | (1 << j)]) {
          f[i | (1 << j)] = f[i] + 1;
          sz[i | (1 << j)] = w - a[j];
        } else if(f[i] + 1 == f[i | (1 << j)]) {
          sz[i | (1 << j)] = max(sz[i | (1 << j)], w - a[j]); 
        }
      }
    }
  }

  cout << f[(1 << n) - 1] << "\n";

  return 0;
}