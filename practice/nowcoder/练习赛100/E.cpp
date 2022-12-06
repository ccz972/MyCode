#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for(int i(a); i <= b; ++ i) 
#define dec(i, a, b) for(int i(a); i >= b; -- i) 

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }

//constexpr double pi = acos(-1);
constexpr int N = 20001;
constexpr int mod = 1e9 + 7;
struct ODT {
  int l, r;
  mutable vector<pair<int, int> > a;
  ODT (int l, int r, vector<pair<int, int> > &a) : l(l), r(r), a(a) {}

  bool operator<(const ODT &T) const {
    return l < T.l;
  }
};

using Iter = set<ODT>::iterator;

set<ODT> odt;

vector<int> f(N, -1);
vector<int> p;

ll ksm(ll a, ll b, ll ret = 1) {
  while(b) {
    if(b & 1) ret = ret * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ret;
}

Iter split(int idx) {
  vector<pair<int, int> > X;
  X.emplace_back(-1, -1);
  auto it = odt.lower_bound({idx, 0, X});
  if(it != odt.end() && it->l == idx) return it;
  -- it;
  auto [l, r, x] = *it;
  odt.erase(it);
  odt.insert({l, idx - 1, x});
  return odt.insert({idx, r, x}).first;
}

ll assign(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  vector<int> cnt(p.size());
  for(auto it = itl; it != itr; ++ it) {
    auto [L, R, X] = *it;
    for(auto [k, v] : X) {
      if(~k) {
        chkmax(cnt[k], v);
      }
    }
  }

  ll ret = 1;
  vector<pair<int, int> > a;

  for(int i = 0; i < p.size(); i ++ ) if(cnt[i]) {
    ret = ret * ksm(p[i], cnt[i]) % mod;
    a.emplace_back(i, cnt[i]);
  }

  if(a.empty()) a.emplace_back(-1, -1);

  odt.erase(itl, itr);
  odt.insert({l, r, a});
  return ret;
}

void solve() {
  
  for(int i = 2; i < N; i ++ ) {
    if(f[i] == -1) {
      f[i] = p.size();
      p.emplace_back(i);
    }
    for(int j = 0; j < p.size(); j ++ ) {
      int now = p[j];
      if(now * i >= N) break;
      f[now * i] = j;
      if(i % now == 0) break;
    }
  }
  
  int n, q; cin >> n >> q;
  // vector<int> a(n + 1);

  for(int i = 1; i <= n; i ++ ) {
    //cin >> a[i];
    int val; cin >> val;
    vector<pair<int, int> > x;
    if(val == 1) {
      x.push_back({-1, -1});
      odt.insert({i, i, x});
    } else {
      
      for(int j = 0; j < p.size() && val > 1; j ++ ) if(val % p[j] == 0) {
        int cnt = 0;
        while(val % p[j] == 0) {
          cnt ++;
          val /= p[j];
        } 
        x.emplace_back(j, cnt);
      }
      odt.insert({i, i, x});
    }
  }
  vector<pair<int, int> > x;
  x.emplace_back(0, 0);
  odt.insert({n + 1, n + 1, x});
  while(q -- ) {
    int l, r; cin >> l >> r;
    cout << assign(l, r) << "\n";
  }

}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
