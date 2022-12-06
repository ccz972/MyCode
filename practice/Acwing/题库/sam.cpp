#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<bitset>
#include<cmath>

#define int long long 
#define x first
#define y second
#define LL long long 
#define ps push_back
#define endl '\n'

#define kd ios::sync_with_stdio(false);cin.tie();cout.tie(0);
using namespace std;
typedef pair<int,int>pi;
const int N=2e5+100,mod=1e9+7;
int lowbit(int x){return x&-x;}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
int tot = 1, last = 1;
struct Node
{
    int len,fa;
    int ch[26];
}node[N];
char str[N];
int w[N];	
int n,m,q;

struct T
{
	int l,r;
	int rs,sum;
}tr[N<<2];

void pushup(T &u,T l,T r)
{
	u.rs=max(r.rs,l.rs+r.sum);
	u.sum=l.sum+r.sum;
}

void pushup(int u)
{
	pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r)
	{
		tr[u].rs=tr[u].sum=w[l];
		return;
	}
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}

T query(int u,int l ,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)
	{
		return tr[u];
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	if(mid>=r)return query(u<<1,l,r);
	if(mid<l)return query(u<<1|1,l,r);
	T c;
	auto l1=query(u<<1,l,r);
	auto r1=query(u<<1|1,l,r);
	pushup(c,l1,r1);
	return c;
}


LL f[N], ans;
vector<int>v[N];

void extend(int c)
{
    int p=last,np=last=++tot;
    f[tot]=1;
    node[np].len=node[p].len+1;
    for(;p&&!node[p].ch[c];p=node[p].fa)node[p].ch[c]=np;
    if(!p)node[np].fa = 1;
    else
    {
        int q = node[p].ch[c];
        if (node[q].len==node[p].len+1)node[np].fa = q;
        else
        {
            int nq = ++ tot;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for (; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}


signed main()
{	
	cin>>n>>m>>q;
    scanf("%s", str);
   
    for (int i=0;str[i];i++)extend(str[i]-'a');
	for(int i=1;i<=m;i++)cin>>w[i];
	build(1,1,m);

	while(q--)
	{
		string t;
		cin>>t;
		int p=1,len=0;
		int ans=0;
		for(int i=0;i<t.size();i++)
		{
			int c=t[i]-'a'; //取出当前的字符
			while(p>1&&!node[p].ch[c])
			{ //如果当前节点不是头节点，并且他后继有 c 那么就一直跳
				p=node[p].fa;
				len=node[p].len;  
			}
			if(node[p].ch[c])
			{
				p=node[p].ch[c];
				len++;
			}
			if(!len)continue;
			// cout<<len<<endl;
			ans=max(ans,query(1,i+1-len+1,i+1).rs);
		}
		cout<<ans<<endl;
	}
    return 0;
}