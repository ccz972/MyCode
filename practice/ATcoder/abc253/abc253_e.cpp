// Problem: E - Distance Sequence
// Contest: AtCoder - NOMURA Programming Contest 2022（AtCoder Beginner Contest 253）
// URL: https://atcoder.jp/contests/abc253/tasks/abc253_e
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

constexpr int mod = 998244353;

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
      fenw[x] = (fenw[x] + v) % mod;
      if(fenw[x] < 0) fenw[x] += mod;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x]; v %= mod;
      if(v < 0) v += mod;
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

void solve() {
  int n, m, k; cin >> n >> m >> k;
	vector<ll> f(m + 1);
	vector<ll> s(m + 1);
	rep(i, 1, m) f[i] = 1, s[i] = s[i - 1] + f[i];
	
	rep(i, 2, n) {
		rep(j, 1, m) {
			if(j > k) {
				f[j] = (k == 0 ? s[j - k - 1] : s[j - k]);
			} else {
				f[j] = 0;
			}
			
			if(j + k <= m) {
				f[j] = (f[j] + (s[m] - s[j + k - 1])) % mod;
				if(f[j] < 0) f[j] += mod;
			}
			
		}
		
		
		rep(j, 1, m) {
			s[j] = (s[j - 1] + f[j]) % mod;
		}
	}
	
	cout << s.back();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

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
