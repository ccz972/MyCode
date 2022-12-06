#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

#define int long long 
#define x first
#define y second
#define ps push_back
#define endl '\n'

#define kd ios::sync_with_stdio(false);cin.tie();cout.tie(0);
using namespace std;
typedef pair<int,int>pi;
const int N=1e5+100,mod=1e9+7;
int lowbit(int x){return x&-x;}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}


vector<int>v1[N],v2[N];
int d1[N],d2[N];
int fa1[N][21],fa2[N][21];
int re[N];
int w1[N],w2[N];
int l1[N],r1[N];
int l2[N],r2[N];

void bfs1(int u,int pr)
{
	queue<int>q;
	q.push(u);
	memset(d1,0x3f,sizeof d1);
	d1[0]=0;d1[u]=1;

	while(q.size())
	{
		int t=q.front();q.pop();
		for(int j:v1[t])
		{
			
			if(d1[j]>d1[t]+1)
			{
				d1[j]=d1[t]+1;
				q.push(j);
				fa1[j][0]=t;
				for(int k=1;k<21;k++)
				{
					fa1[j][k]=fa1[fa1[j][k-1]][k-1];
				}
			}
		}
	}	
}

void bfs2(int u,int pr)
{
	queue<int>q;
	q.push(u);
	memset(d2,0x3f,sizeof d2);
	d2[0]=0;d2[u]=1;

	while(q.size())
	{
		int t=q.front();q.pop();
		for(int j:v2[t])
		{
			
			if(d2[j]>d2[t]+1)
			{
				d2[j]=d2[t]+1;
				q.push(j);
				fa2[j][0]=t;
				for(int k=1;k<21;k++)
				{
					fa2[j][k]=fa2[fa2[j][k-1]][k-1];
				}
			}
		}
	}	
}


int get1(int x,int y)
{
	if(d1[x]<d1[y])swap(x,y);

	for(int i=20;i>=0;i--)
	{
		if(d1[fa1[x][i]]>=d1[y])
		{
			x=fa1[x][i];
		}
	}
	if(x==y)return x;
	
	for(int i=20;i>=0;i--)
	{
		if(fa1[x][i]!=fa1[y][i])
		{
			x=fa1[x][i];
			y=fa1[y][i];
		}
	}
	return fa1[x][0];
}

int get2(int x,int y)
{
	if(d2[x]<d2[y])swap(x,y);

	for(int i=20;i>=0;i--)
	{
		if(d2[fa2[x][i]]>=d2[y])
		{
			x=fa2[x][i];
		}
	}
	if(x==y)return x;
	
	for(int i=20;i>=0;i--)
	{
		if(fa2[x][i]!=fa2[y][i])
		{
			x=fa2[x][i];
			y=fa2[y][i];
		}
	}
	return fa2[x][0];
}

void solve()
{
	int n,k;cin>>n>>k;
    for(int i=1;i<=k;i++)cin>>re[i];
    for(int i=1;i<=n;i++)cin>>w1[i];
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        v1[x].ps(i);
    } 
    for(int i=1;i<=n;i++)cin>>w2[i];
    for(int i=2;i<=n;i++)
    {
        int x;cin>>x;
        v2[x].ps(i);
    }
    bfs1(1,-1);
    bfs2(1,-1);
    
    l1[1]=l2[1]=1;
    r1[n]=r2[n]=n;

  l1[1] = re[1];
  l2[1] = re[1];

  for(int i=2;i<=k;i++)
  {
    l1[i]=get1(re[i],l1[i-1]);
    l2[i]=get2(re[i],l2[i-1]);
  }
  r1[k] = re[k];
  r2[k] = re[k];
  for(int i=k-1;i>=1;i--)
  {
    r1[i]=get1(re[i],r1[i+1]);
    r2[i]=get2(re[i],r2[i+1]);
  }
  int res=0;
  for(int i=1;i<=k;i++)
  {
    int a, b;
    if(i == 1) a = r1[i + 1], b = r2[i + 1];
    else if(i == k) a = l1[i - 1], b = l2[i - 1];
    else a=get1(l1[i-1],r1[i+1]), b = get2(l2[i-1],r2[i+1]);
    if(w1[a]>w2[b])res++;
  }
  cout<<res<<endl;
	
}

signed main()
{
	kd;
	int _;_=1;
	//cin>>_;
	while(_--)solve();	
	return 0;
}
