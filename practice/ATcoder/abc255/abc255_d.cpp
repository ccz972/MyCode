// Problem: D - ±1 Operation 2
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }
template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

template<typename T> 
inline void Discrete (vector<T> &ans) {
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
}


void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n); for(int &x: a) cin >> x;
  auto all = a;
  vector<int> que(q);
  for(int &x: que) cin >> x, all.push_back(x);
  Discrete(all);
  // sort(all.begin(), all.end());
  // all.erase(unique(all.begin(), all.end()), all.end());
  auto find = [&] (int x) {
  	return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };
  sort(a.begin(), a.end());
  fenwick<ll> fen((int)all.size() + 100);
	for(int x: a) {
		fen.modify(find(x), x);
	}
	vector<ll> ans(q);
	auto get = [&] (int x) -> ll{
		int idx = find(x);
		int cnt = upper_bound(a.begin(), a.end(), x) - a.begin();
		ll ans = 0;
		ans -= fen.get(idx);
		ans += 1ll * cnt * x;
		ans -= 1ll * (n - cnt) * x;
		ans += fen.get((int)all.size()) - fen.get(idx);
		return ans;
	};
	for(int i = 0; i < q; i ++ ) {
		ans[i] = get(que[i]);
	}
	for(auto x: ans) cout << x << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;// cin >> T;
  while(T --) solve();

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
