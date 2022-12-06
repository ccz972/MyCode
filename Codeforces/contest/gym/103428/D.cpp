#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;

typedef pair<ull, ull> Hash;

constexpr Hash mod = {1000000069, 1000000067};

Hash operator * (const Hash &a, const Hash &b) {
  return {a.fi * b.fi % mod.fi, a.se * b.se % mod.se};
}

Hash operator + (const Hash &a, const Hash &b) {
  return {a.fi + b.fi % mod.fi, a.se + b.se % mod.se};
}


Hash operator - (const Hash &a, const Hash &b) {
  return {(a.fi - b.fi + mod.fi) % mod.fi, (a.se - b.se + mod.se) % mod.se};
}


Hash operator * (const Hash &a, const ull &b) {
  return {a.fi * b % mod.fi, a.se * b % mod.se};
}




void solve() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  Hash base = {rng() % mod.fi, rng() % mod.se};
  string s; cin >> s;
  int n = s.size();
  s = " " + s;

  vector<Hash> p(n + 1), a(n + 1);

  p[0] = a[0] = {1, 1};
  for(int i = 1; i <= n; i ++ ) {
    p[i] = p[i - 1] * base;
  }
  for(int i = 1; i <= n; i ++ ) {
    a[i] = a[i - 1] * base + p[0] * (s[i] - 'a' + 1);
  } 

  auto get = [&] (int l, int r) {
    return a[r] - a[l - 1] * p[r - l + 1];
  };

  vector<int> S(n + 1);

  for(int i = n; i >= 1; i -- ) {
    int l1 = i, r1 = n;
    int l2 = 1, r2 = i - 1;
    if(r2 - l2 <= r1 - l1) continue;
    r2 = l2 + (r1 - l1);
    if(get(l1, r1) == get(l2, r2)) S[i - 1] = 1;
  }
  for(int i = n - 1; i >= 0; i -- ) {
    S[i] = S[i] + S[i + 1];
  }
  int q; cin >> q;
  while(q -- ) {
    int x; cin >> x;
    int r = x;
    r = max(r, n - x + 1);
    if(r == n) {
      cout << "0\n";
    } else {
      cout << S[r] << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();

  return 0;
}
