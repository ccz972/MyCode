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
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

//求区间最大值 最小值
struct Node {
  ll maxi_v = 0, maxi_id = 0, mini_v = inf, mini_id = 0, init = 0;
};
 
Node pull(const Node &a, const Node &b) {
  if (!a.init) return b;
  if (!b.init) return a;
  Node c = a;
  if (b.maxi_v > c.maxi_v) c.maxi_v = b.maxi_v, c.maxi_id = b.maxi_id;
  if (b.mini_v < c.mini_v) c.mini_v = b.mini_v, c.mini_id = b.mini_id;
  return c;
}
 
struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node &v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  


  return 0;
}