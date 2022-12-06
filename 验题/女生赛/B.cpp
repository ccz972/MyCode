#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll INFF = 0x3f3f3f3f3f3f3f3f;
// constexpr int N = 2E5 + 10;

const int N = 1e5 + 10,M = N * 2;

int h[N],e[M],ne[M],w[N],idx;
int fa[N],dep[N],sz[N],son[N];
int top[N],dfn[N],ts;
ll sum[N];
int n,m,q;

struct cmp
{
  bool operator()(const int &a,const int &b) const
  {
    return dfn[a] < dfn[b];
  }
};

set<int,cmp> s;

void add(int a,int b) 
{
  e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void dfs1(int u,int pa)
{
  sz[u] = 1;
  for(int i=h[u];~i;i=ne[i])
  {
    int j = e[i];
    if(j==pa) continue;
    dep[j] = dep[u] + 1;
    dfs1(j,u);
    fa[j] = u;sz[u] += sz[j];
    if(sz[j]>sz[son[u]]) son[u] = j;
  }
}

void dfs2(int u,int tp)
{
  top[u] = tp;dfn[u] = ++ts;
  if(!son[u]) return ;
  sum[son[u]] = sum[u] + w[son[u]];
  dfs2(son[u],tp);
  for(int i=h[u];~i;i=ne[i])
  {
    int j = e[i];
    if(j==fa[u]||j==son[u]) continue;
    sum[j] = sum[u] + w[j];
    dfs2(j,j);
  }
}

int lca(int a,int b)
{
  while(top[a]!=top[b])
  {
    if(dep[top[a]]<dep[top[b]]) swap(a,b);
    a = fa[top[a]];
  }
  return dep[a]<dep[b]?a:b;
}

ll dist(int a,int b)
{
  int anc = lca(a,b);
  return sum[a] + sum[b] - 2*sum[anc];
}

ll add(int u)
{
  ll res = 0;
  if(s.size())
  {
    auto it = dfn[u] < dfn[*s.rbegin()] ? s.lower_bound(u) : s.begin();
    res += dist(*it,u);
    auto iit = it;
    if(iit == s.begin()) iit = s.end();
    res += dist(*--iit,u);res -= dist(*it,*iit);
  }
  s.insert(u);
  return res;
}

ll del(int u)
{
  ll res = 0;
  s.erase(u);
  if(s.size())
  {
    auto it = dfn[u] < dfn[*s.rbegin()] ? s.lower_bound(u) : s.begin();
    res -= dist(*it,u);
    auto iit = it;
    if(iit == s.begin()) iit = s.end();
    res -= dist(*--iit,u);res += dist(*it,*iit);
  }
  return res;
}

void solve() {
  cin>>n>>m>>q;
  for(int i=1;i<=n;i++) cin>>w[i],h[i] = -1,sz[i] = 0,dep[i] = 0,son[i] = 0;
  s.clear();
  idx = ts = 0;
  for(int i=0;i<n-1;i++)
  {
    int u,v;cin>>u>>v;
    add(u,v),add(v,u);
  }
  sum[1] = w[1];
  dfs1(1,-1),dfs2(1,1);
  ll ans = 0;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    ans += add(x);
  }
  while(q--)
  {
    int op,u;cin>>op>>u;
    if(op==1) ans += add(u);
    else ans += del(u);
    if(!s.size()) cout<<0<<'\n';
    else cout<<ans/2 + w[lca(*s.begin(),*s.rbegin())]<<'\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}