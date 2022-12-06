#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y);  }

constexpr int N = 1E6 + 10;

int n;
int a[N];
int p[N];
int id[N];
int ans[N];
int pans[N];

int find(int x) {
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void solve() {
  for(int i = 1; i < N; i ++ ) p[i] = id[i] = i;
  cin >> n;
  for(int i = 1; i <= n; i ++  ) {
    cin >> a[i];
  }
  sort(id + 1, id + 1 + n, [&](int x, int y) {
    return a[x] < a[y];
  });
  int m = max(n, a[id[n]]) + 10;
  int start = 1;
  for(int i = 1; i <= n; i ++ ) {
    int idx = id[i];
    int val = a[idx];
    while(ans[start]) ++ start;
    assert(start <= val);
    for(int j = start; j <= m; j = find(j + val)) {
      ans[j] = idx;
      p[j] = j - 1; 
      assert(find(j + val) != 0);
    }
  }
  
  
  n = 0;
  
  for(int i = 1; i <= m; i ++ ) {
    if(ans[i]) pans[++ n] = ans[i];
  }
  cout << n << "\n";
  for(int i = 1; i <= n; i ++ ) {
    cout << pans[i] << " ";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("1.txt", "w", stdout);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}
/*
1
5 5
..B..
.....
B..A.
.A...
.....


1
5 5
..B..
.....
B....
.....
.....

*/