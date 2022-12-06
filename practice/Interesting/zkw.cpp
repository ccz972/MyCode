#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  ll n;
  vector<int> t;
  SegTree(ll _n) : n(_n), t(2 * n) {}
  void modify(ll p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(ll l, ll r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      cout << "l, r = : " << l << " " << r << "\n"; 
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
      cout << "new l, r = : " << l << " " << r << "\n----\n";

    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  
  SegTree seg(n);
  for(int i = 0; i < n; i ++ ) {
    seg.t[i + n] = a[i];
  }

  for(int i = n - 1; i >= 0; i -- ) {
    seg.t[i] = seg.t[i * 2] + seg.t[i * 2 + 1];
  }

  cout << seg.query(0, 5);

  return 0;
}