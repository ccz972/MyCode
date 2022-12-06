struct DSU_DEL {
  int n;
  vector<int> f, sz; 
  vector<pair<int&, int> > his_sz;
  vector<pair<int&, int> > his_fa;
  DSU_DEL(int _n) : n(_n), f(_n), sz(_n, 1) { iota(f.begin(), f.end(), 0); }

  int find(int x) {
    while (x != f[x]) x = f[x]; 
    return x;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }
  int size(int u) {
    return sz[find(u)];
  }
  void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv) return ;
    if (sz[fu] < sz[fv]) swap(fu, fv);
    his_sz.push_back({sz[fu], sz[fu]});
    sz[fu] += sz[fv];
    his_fa.push_back({f[fv], f[fv]});
    f[fv] = fu;
  }

  int history() {
    return his_fa.size();
  }

  void roll(int h) {
    while (his_fa.size() > h) {
      his_fa.back().first = his_fa.back().second;
      his_fa.pop_back();
      his_sz.back().first = his_sz.back().second;
      his_sz.pop_back();
    }
  }
};