#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 410;
constexpr int mid = 400010;

// int v[N], w[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> f(mid * 2 + 100, -1e9);
  f[mid] = 0;
  for (int i = 0; i < n; i ++ ) {
    int v, w; cin >> v >> w;
    auto g = f;
    for(int j = -mid; j < mid; j ++ ) {
      if(j + mid + v >= 0 && j + mid + v <= mid * 2) {
        g[j + mid + v] = max(g[j + mid + v], f[j + mid] + w); 
      }
    }
    f.swap(g);
  }
  int ans = 0;
  for(int i = mid; i <= mid * 2; i ++ ) {
    if(f[i] >= 0) {
      ans = max(ans, i - mid + f[i]);
    }
  }
  cout << ans << "\n";

  return 0;
}