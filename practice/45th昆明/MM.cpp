#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(s) ((int)s.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define PII pair<int, int>

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}

const int N = 1e6 + 10,M = N * 40;
const ll inf = 1e9 + 10;

struct node {
  int l, r;
  ll sum;
} tr[M];

int n, m, tot, rt[N];
ll ans;

void pushup(int u)
{
  tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
}

void modify(int &x, int y, ll l, ll r, ll p) 
{
  x = ++tot;
  tr[x] = tr[y];
  if(l==r) 
  {
    tr[x].sum += p;
    return ;
  }
  ll mid = l + r >> 1;
  if (p <= mid) modify(tr[x].l, tr[y].l, l, mid, p);
  else modify(tr[x].r, tr[y].r, mid + 1, r, p);
  pushup(x);
}

ll query(int x, int y, ll l, ll r, ll p) 
{
  if (p >= r) return tr[x].sum - tr[y].sum;
  if (p < l)  return 0;
  if (!x && !y) return 0;
  ll mid = l + r >> 1;
  return query(tr[x].l, tr[y].l, l, mid, p) + query(tr[x].r, tr[y].r, mid + 1, r, p);
}

void solve()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++) 
  {
    ll x;cin >> x;
    modify(rt[i], rt[i - 1], 1ll, inf, x);
  }
  while (m--) 
  {
    int l, r;
    cin >> l >> r;
    l = (l + ans) % n + 1;r = (r + ans) % n + 1;
    if(l>r) swap(l,r);
    ans = 1;
    while (1) 
    {
      ll x = min(inf, ans);
      ll res = query(rt[r], rt[l - 1], 1, inf, x) + 1;
      if (res <= ans) break;
      ans = res;
    }
    cout << ans << "\n";
  }
}

int main() 
{
  ios::sync_with_stdio(false);cin.tie(0);
  int T = 1;
  // cin>>T;
  while(T--) solve();
  return 0;
}
