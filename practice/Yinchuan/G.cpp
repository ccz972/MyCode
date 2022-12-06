#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define rep(i, a, b) for (int i(a); i <= (b); i ++ )
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define all(a) a.begin(), a.end()

const int N = 1e5 + 10;
struct node
{
  int l,r;
  int mx,add;
}tr[4][N<<2];
int mp[10];
int n,q;

void pushup(int u,int k)
{
  tr[k][u].mx = max(tr[k][u<<1].mx,tr[k][u<<1|1].mx);
}

void build(int u,int l,int r,int k)
{
  tr[k][u] = {l,r};
  if(l==r) return ;
  int mid = l + r >> 1;
  build(u<<1,l,mid,k),build(u<<1|1,mid+1,r,k);
  pushup(u,k);
}

void pushdown(int u,int k)
{
  auto &root = tr[k][u],&left = tr[k][u<<1],&right = tr[k][u<<1|1];
  if(root.add)
  {
    left.add += root.add;left.mx += root.add;
    right.add += root.add;right.mx += root.add;
    root.add = 0;
  }
}

void modify(int u,int l,int r,int x,int k)
{
  if(l>tr[k][u].r||tr[k][u].l>r) return ;
  // cout<<tr[k][u].l<<" "<<tr[k][u].r<<endl;
  if(l<=tr[k][u].l&&tr[k][u].r<=r) 
  {
    tr[k][u].mx += x;
    tr[k][u].add += x;
    return ;
  }
  pushdown(u,k);
  modify(u<<1,l,r,x,k),modify(u<<1|1,l,r,x,k);
  pushup(u,k);
}

int query(int u,int l,int r,int k)
{
  if(l>tr[k][u].r||tr[k][u].l>r) return 0;
  if(l<=tr[k][u].l&&tr[k][u].r<=r) return tr[k][u].mx;
  pushdown(u,k);
  return max(query(u<<1,l,r,k),query(u<<1|1,l,r,k));
}

void solve() {
  cin>>n>>q;
  for(int i=0;i<4;i++) build(1,1,n,i);
  while(q--)
  {
    string s;
    int l,r,x;cin>>s>>l>>r;
    if(s[1]=='U') 
    {
      cin>>x;
      for(int i=0;i<4;i++)
        if(x%mp[i]==0)
        {
          int cnt = 0;
          while(x%mp[i]==0) x /= mp[i],cnt++;
          modify(1,l,r,cnt,i);
          // cout<<cnt<<endl;
          // return ;
        }
    }
    else 
    {
      int ans = 0;
      for(int i=0;i<4;i++)
        ans = max(ans,query(1,l,r,i));
      cout<<"ANSWER "<<ans<<'\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mp[0] = 2,mp[1] = 3,mp[2] = 5,mp[3] = 7,mp[4] = 9;
  solve();
  return 0;
}