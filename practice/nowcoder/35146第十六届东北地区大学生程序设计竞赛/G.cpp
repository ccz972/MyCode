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


constexpr int N = 1e6 + 10;

int a[N];

struct node {
  ll t, x, cnt;
  //时间 温度 个数
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, Tmin, Tmax;
  cin >> n >> m >> Tmin >> Tmax;
  int mod = Tmax - Tmin + 1; //length
  deque<node> dq;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    dq.emplace_back(node{0, a[i], 1});
  }
  ll now = 0;
  while (m -- ) {
    ll T, k; cin >> T >> k; //过去 T 取出k个
    now += T;
    ll ans = 0, sum = 0;
    while(!dq.empty() && k) {
      auto[t, x, cnt] = dq.back();
      dq.pop_back();
      ll p = (now - t) % mod;
      x -= p;
      if (x < Tmin) x += mod;
      ll q = min(cnt, k);
      ans += x * q;
      sum += q; //一共取出多少个
      cnt -= q;
      k -= q;
      if (cnt > 0) {
        dq.emplace_back(node{now, x, cnt});
      }
    }
    if(k) ans += Tmax * k;
    dq.emplace_front(node{now, Tmax, sum});
    cout << ans << "\n";
  }



  return 0;
}