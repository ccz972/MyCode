// #include  <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// #define rep(i, a, b) for(int i(a); i <= b; i ++)
// #define dec(i, a, b) for(int i(a); i >= b; i --)

// #ifdef LOCAL
// #include <debugger>
// #else
// #define debug(...) 42
// #endif


// template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
// template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }

// constexpr int mod = 998244353;
// constexpr int inv = 499122177;
// struct ODT {
// 	ll l, r;
// 	mutable ll v;
// 	bool operator < (const ODT &T ) const {
// 		return l < T.l;
// 	}
// };

// set<ODT> odt;

// using Iter = set<ODT>::iterator;

// Iter split(ll pos) {
// 	auto it = odt.lower_bound({pos, 0, 0});
// 	if(it != odt.end() && it->l == pos) return it;
// 	-- it;
// 	auto [l, r, v] = *it;
// 	odt.erase(it);
// 	odt.insert({l, pos - 1, v});
// 	return odt.insert({pos, r, v}).first;
// }

// ll assign(ll l, ll r, ll v) {
// 	auto itr = split(r + 1), itl = split(l);
	
// 	ll ret = 0;
// 	for(auto it = itl; it != itr; it ++ ) {
// 		auto [x, y, v0] = *it;
// 		ret += (v - v0) % mod * ((x + y) % mod) % mod * ((y - x + 1) % mod) % mod * inv % mod;
// 	}
	
// 	odt.erase(itl, itr);
// 	odt.insert({l, r, v}); 
// 	return ret % mod;
// }

// void solve() {
//   int q; cin >> q; 
//   int n = q + 10;
//   odt.insert({0, n, 0});
//   int m = 0;

//   while (q -- ) {
//     int op; cin >> op;
//     if (op == 1) { // add a number
//       ++ m;

//     } else if (op == 2) {

//     } else if (op == 3) {

//     } else {

//     }
//   }
//   // ll n, q; cin >> n >> q;
//   // odt.insert({1, n, 0});
//   // while(q -- ) {
//   // 	ll l, r, d;
//   // 	cin >> d >> l >> r;
//   // 	cout << assign(l, r, d) << "\n";
//   // }
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
// 	solve();

//   return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

struct ODT {
  int l, r;
  mutable int val, g;
  bool operator < (const ODT &T) const {
    return l < T.l;
  }
};

void solve() {
  int q; cin >> q;
  int n = q + 1, m = 0, x;
  vector<ODT> s;
  s.push_back({0, 0, 0, 0});
  while (q -- ) {
    int op; cin >> op;
    if (op == 1) { // add a number
      ++ m;
      cin >> x;
      auto g = s.back().g;
      s.push_back({m, m, x, __gcd(x, g)});
    } else if (op == 2) {
      -- m;
      auto [l, r, val, g] = s.back();
      s.pop_back();
      if (l <= r - 1) {
        s.push_back({l, r - 1, val, g});
      }
    } else if (op == 3) {
      auto [l, r, val, g] = s.back();
      cout << val << "\n";
    } else {
      
      int k; cin >> k;
      if (!k) continue;

      int L = m - k + 1, R = m;
      int G = 0;
      while (true) {
        // auto it = prev(s.end());
        auto [l, r, val, g] = s.back();
        if (l < L) break;
        G = __gcd(G, val);
        s.pop_back();
      }

      auto [l, r, val, g] = s.back();

      if (r >= L && r <= R) {
        G = __gcd(G, val);
        s.pop_back();
        s.push_back({l, L - 1, val, g});
      }

      s.push_back({L, R, G, __gcd(g, G)});
    }
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
