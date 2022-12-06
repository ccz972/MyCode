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

constexpr int N = 1e5 + 10;
constexpr int inf = 1e9;
constexpr int M = 100000;
int cnt[N]; 
struct segment {
	struct node {int l, r; ll lmax, rmax, tmax, sum; }tr[N * 4];
	//tmax 最大连续子段和
	//lmax rmax 
	#define lson u << 1
	#define rson u << 1 | 1
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
			tr[u] = {l, r, -inf, -inf, -inf, -inf};
		} else {
			tr[u] = {l, r};
			build(lson, l, Mid);
			build(rson, Mid + 1, r);
			pushup(u);
		}
	}
	
	void modify(int u, int k, int c) {
		if(tr[u].l == k && tr[u].r == k) {
			tr[u] = {k, k, c, c, c, c};
		} else if(tr[u].l > k || tr[u].r < k) {
			return ;
		} else {
			modify(lson, k, c);
			modify(rson, k, c);
			pushup(u);
		}
	}

	node query(int u, int l, int r) {
		if(tr[u].l >= l && tr[u].r <= r) return tr[u];
		if(r <= mid) return query(lson, l, r);
		if(l > mid) return query(rson, l, r);
		
		node ans;
		node left = query(lson, l, r);
		node right = query(rson, l, r);
		pushup(ans, left, right);
		return ans;
	}
		
}T[2];
void solve() {
  int q; cin >> q;

  T[0].build(1, 1, 100000);
  T[1].build(1, 1, 100000);
  // cout << T[0].tr[1].sum  << "\n";
  // cout << TTT << "\n";
  while(q -- ) {
		int op; cin >> op;
		if(op == 1) {
			int x; cin >> x;
			if(!cnt[x]) {
				//1 2 3 4 5 6
				//
				T[x & 1].modify(1, (x + 1) / 2, 1);
			}
			cnt[x] ++;
		} else if(op == 2) {
			int x; cin >> x;
			if(cnt[x] == 1) {
				cnt[x] --;
				T[x & 1].modify(1, (x + 1) / 2, -inf);
				//delete
			} else if(cnt[x] > 1) {
				cnt[x] --;
			}
		} else {
			int ans = max(T[0].query(1, 1, 100000).tmax, T[1].query(1, 1, 100000).tmax);
			// chkmax(ans, T[0].tr[1].tmax);
			// chkmax(ans, T[1].tr[1].tmax);
			chkmax(ans, 0ll);
			cout << ans << "\n";
		} 	
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
