#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672346917


#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long LL;
typedef pair<int, int> PII;

constexpr int inf = 0x3f3f3f3f;
constexpr double EPS = 1e-8;
const double PI = acos(-1);

int multi_cases = 0;

template <class Info>
struct DynamicSegTree {
  int n, N;
  vector<Info> tr = {{}, {}};
  DynamicSegTree() {}
  DynamicSegTree(int _n, int _N) : n(_n), N(_N) { tr.reserve(n * 50); }
  DynamicSegTree(int _n, int _N, const Info _init) : DynamicSegTree(_n, _N) {
    tr[1] = _init;
  }
  int newNode(int u, int l, int r) {
    if (!u) {
      tr.push_back(tr[0]);
      u = (int)tr.size() - 1;
      tr[u].val = r - l + 1;
    }
    return u;
  }
  void pushup(int u) { tr[u].val = tr[tr[u].lc].val + tr[tr[u].rc].val; }
  void apply(int u, int l, int r, const int &v) {
    if (v == -1) {
      return;
    }
    tr[u].val = v * (r - l + 1);
    tr[u].tag = v;
  }
  void pushdown(int u, int l, int r) {
    if (l == r) {
      return;
    }
    int mid = l + r >> 1;
    tr[u].lc = newNode(tr[u].lc, l, mid);
    tr[u].rc = newNode(tr[u].rc, mid + 1, r);
    apply(tr[u].lc, l, mid, tr[u].tag);
    apply(tr[u].rc, mid + 1, r, tr[u].tag);
    tr[u].tag = -1;
  }
  void rangeModify(int u, int l, int r, int ql, int qr, const int &v) {
    if (l > qr || r < ql) {
      return;
    }
    if (ql <= l && r <= qr) {
      apply(u, l, r, v);
      return;
    }
    int mid = l + r >> 1;
    pushdown(u, l, r);
    rangeModify(tr[u].lc, l, mid, ql, qr, v);
    rangeModify(tr[u].rc, mid + 1, r, ql, qr, v);
    pushup(u);
  }
  void rangeModify(int l, int r, const int &v) {
    rangeModify(1, 1, N, l, r, v);
  }
  Info query(int u, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
      return Info();
    }
    if (ql <= l && r <= qr) {
      return tr[u];
    }
    int mid = l + r >> 1;
    pushdown(u, l, r);
    return query(tr[u].lc, l, mid, ql, qr) +
           query(tr[u].rc, mid + 1, r, ql, qr);
  }
  Info query(int l, int r) { return query(1, 1, N, l, r); }
};

struct Info {
  int lc = 0, rc = 0;
  int val = 0, tag = -1;
};

Info operator+(const Info &l, const Info &r) { return {0, 0, l.val + r.val}; }

void A_SOUL_AvA() {
  int n, q;
  cin >> n >> q;

  DynamicSegTree<Info> st(q, n, {0, 0, n, -1});

  for (int i = 1; i <= n; i ++ ) {

  }

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    k--;

    st.rangeModify(l, r, k);
    cout << st.query(1, n).val << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int T = 1;
  for (multi_cases &&cin >> T; T; T--) {
    A_SOUL_AvA();
  }

  return 0;
}