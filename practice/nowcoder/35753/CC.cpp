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

constexpr int N = 5e5 + 100;
constexpr int inf = 1e9;


// struct segment {
	// struct node {int l, r; ll lmax, rmax, tmax, sum; }tr[N * 4];
	// //tmax 最大连续子段和
	// //lmax rmax 
	// #define lson u << 1
	// #define rson u << 1 | 1
	// #define Mid (l + r) / 2
	// #define mid (tr[u].l + tr[u].r) / 2
	// void pushup(node &u, node &l, node &r) {
		// u.lmax = max(l.lmax, l.sum + r.lmax);
		// u.rmax = max(r.rmax, r.sum + l.rmax);
		// u.sum = l.sum + r.sum;
		// u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
	// }
// 	
	// void pushup (int u) {
		// pushup(tr[u], tr[lson], tr[rson]);
	// }
// 	
	// void build(int u, int l, int r) {
		// if(l == r) {
			// tr[u] = {l, r, w[l], w[l], w[l], w[l]};
		// } else {
			// tr[u] = {l, r};
			// build(lson, l, Mid);
			// build(rson, Mid + 1, r);
			// pushup(u);
		// }
	// }
// 	
	// void modify(int u, int k, int c) {
		// if(tr[u].l == k && tr[u].r == k) {
			// tr[u] = {k, k, c, c, c, c};
		// } else if(tr[u].l > k || tr[u].r < k) {
			// return ;
		// } else {
			// modify(lson, k, c);
			// modify(rson, k, c);
			// pushup(u);
		// }
	// }
// 
	// node query(int u, int l, int r) {
		// if(tr[u].l >= l && tr[u].r <= r) return tr[u];
		// if(r <= mid) return query(lson, l, r);
		// if(l > mid) return query(rson, l, r);
// 		
		// node ans;
		// node left = query(lson, l, r);
		// node right = query(rson, l, r);
		// pushup(ans, left, right);
		// return ans;
	// }
// 		
// }T;

int w[N];
struct segment {
	struct node {int l, r; int lmax, rmax, tmax, sum; } tr[N << 2];
	#define lson (u << 1)
	#define rson (u << 1 | 1)
	#define Mid (l + r) / 2
	#define mid (tr[u].l + tr[u].r) / 2
	void pushup(node &u, node &l, node &r) {
		u.lmax = max(l.lmax, l.sum + r.lmax);
		u.rmax = max(r.rmax, r.sum + l.rmax);
		u.sum = l.sum + r.sum;
		u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
	}
	
	void pushup (int u) {
		pushup(tr[u], tr[lson], tr[rson]);
	}
		
	void build(int u, int l, int r) {
		if(l == r) {
			tr[u] = {l, r, w[l], w[l], w[l], w[l]};
		} else {
			tr[u] = {l, r};
			build(lson, l, Mid), build(rson, Mid + 1, r);
			pushup(u);
		}
	}
	
	void modify(int u, int idx, int val) {
		if(tr[u].l >= idx && tr[u].r <= idx) {
			tr[u] = {idx, idx, val, val, val, val};
		} else if(tr[u].l > idx || tr[u].r < idx) {
			return ;
		} else {
			modify(lson, idx, val);
			modify(rson, idx, val);
			pushup(u);
		}
	}
	
	node query(int u, int l, int r) {
		if(tr[u].l >= l && tr[u].r <= r) {
			return tr[u];
		} else if(r <= mid) {
			return query(lson, l, r);
		} else if(l > mid) {
			return query(rson, l, r);
		} else {
			node ans;
			node left = query(lson, l, r);
			node right = query(rson, l, r);
			pushup(ans, left, right);
			return ans;
		}
	}
	
}T;

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> w[i];
  T.build(1, 1, n);
  while(m -- ) {
  	int op, x, y;
  	cin >> op >> x >> y;
  	if(op & 1) {
  		if(x > y) swap(x, y);
  		cout << T.query(1, x, y).tmax << "\n";
  	}
  	else T.modify(1, x, y);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
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
