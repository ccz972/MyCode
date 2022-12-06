#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

const int N = 1e5 + 10, M = 2 * N;
int n, m;
int h[N], e[M], ne[M], w[N], idx;
int id[N], nw[N], cnt;
int fa[N], dep[N], son[N], sz[N], top[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs1(int u, int father, int depth){
    fa[u] = father, dep[u] = depth, sz[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == father) continue;
        dfs1(j, u, depth + 1);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j]) son[u] = j;
    }
}

void dfs2(int u){
    id[u] = ++ cnt;
    if(!son[u]) return;
    dfs2(son[u]);
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[u] || j == son[u]) continue;
        dfs2(j);
    }
}

const int maxn = 1e7;
int rt[10010], lc[maxn], rc[maxn], sum[maxn];
int dd = 10010;
void pushup(int u){
    sum[u] = sum[lc[u]] + sum[rc[u]];
}
void modify(int &u, int l, int r, int x){
    if(!u) u = ++ dd;
    if(l == r){
        sum[u] = 1; return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) modify(lc[u], l, mid, x);
    else modify(rc[u], mid + 1, r, x);
    pushup(u);
}
int query(int u, int l, int r,int L, int R){
    if(!u) return 0;
    if(L <= l && R >= r) return sum[u];
    int res = 0;
    int mid = (l + r) >> 1;
    if(L <= mid) res += query(lc[u], l, mid, L, R);
    if(R > mid) res += query(rc[u], mid + 1, r, L, R);
    return res;
}


i64 query_tree(int t, int u){
    return query(rt[t], 1, n, id[u], id[u] + sz[u] - 1);
}

void solve() {
    for(int i = 1; i <= 10000; i ++) rt[i] = i;
    memset(h, -1, sizeof h);
    int n; cin >> n;
    for(int v = 2; v <= n; v ++){
        int u; cin >> u;
        add(u, v);
    }
    dfs1(1, -1, 1);
    dfs2(1);
    int m; cin >> m;
    while(m --){
        int op, x, y; cin >> op >> x >> y;
        if(op == 1){
            modify(rt[y], 1, n, id[x]);
        }
        else cout << query(rt[y], 1, n, id[x], id[x] + sz[x] - 1) << endl;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
