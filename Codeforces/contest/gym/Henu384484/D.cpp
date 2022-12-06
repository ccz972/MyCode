#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	long long sum = 0;
	vector<bool> vis(n);
	vector<int> a(k); for(int &x: a) cin >> x, -- x, vis[x] = true;
	struct node {int u, v, w; bool operator <(const node &T) const {
		if(w != T.w)
			return w > T.w;
		if(u != T.u) 
			return u < T.u;
		return v < T.v;
	}};
	vector<node> edge(n - 1);
	for(auto &[u, v, w] : edge) {
		cin >> u >> v >> w;
		-- u, -- v;
		sum += w;
	}
	sort(edge.begin(), edge.end());
	vector<int> dsu(n);
	iota(dsu.begin(), dsu.end(), 0);
	function<int(int)> find = [&] (int u) {
		if(u != dsu[u]) dsu[u] = find(dsu[u]);
		return dsu[u];
	};
	for(int i = 0; i < n - 1; i ++ ) {
		auto [u, v, w] = edge[i];
		int fu = find(u), fv = find(v);
		if(vis[fu] && vis[fv]) continue;
		sum -= w;
		dsu[fu] = fv;
		if(vis[fu]) 
			vis[fv] = true;
		if(vis[fv])
			vis[fu] = true;
		cout << sum << "\n";
	}
	cout << sum << "\n";
	return 0;
}