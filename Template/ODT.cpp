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
constexpr int inv = 499122177;
struct ODT {
	ll l, r;
	mutable ll v;
	bool operator < (const ODT &T ) const {
		return l < T.l;
	}
};

set<ODT> odt;

using Iter = set<ODT>::iterator;

Iter split(ll pos) {
	auto it = odt.lower_bound({pos, 0, 0});
	if(it != odt.end() && it->l == pos) return it;
	-- it;
	auto [l, r, v] = *it;
	odt.erase(it);
	odt.insert({l, pos - 1, v});
	return odt.insert({pos, r, v}).first;
}

ll assign(ll l, ll r, ll v) {
	auto itr = split(r + 1), itl = split(l);
	
	ll ret = 0;
	for(auto it = itl; it != itr; it ++ ) {
		auto [x, y, v0] = *it;
		ret += (v - v0) % mod * ((x + y) % mod) % mod * ((y - x + 1) % mod) % mod * inv % mod;
	}
	
	odt.erase(itl, itr);
	odt.insert({l, r, v}); 
	return ret % mod;
}

void solve() {
  ll n, q; cin >> n >> q;
  odt.insert({1, n, 0});
  while(q -- ) {
  	ll l, r, d;
  	cin >> d >> l >> r;
  	cout << assign(l, r, d) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	solve();

  return 0;
}
