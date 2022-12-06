#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 25010,M = 2e5 + 10,inf = 2e9;
int h[N],e[M],ne[M],w[M],idx;
int id[N],d[N],p[N],dist[N];
bool st[N];
vector<int> S[N];
int n,x,y,s,cnt;

void add(int a,int b,int c)
{
  e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

int find(int x)
{
  if(p[x]!=x) p[x] = find(p[x]);
  return p[x];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>x>>y>>s;
  for(int i=1;i<=n;i++) h[i] = -1,dist[i] = inf,p[i] = i;
  dist[s] = 0;
  while(x--)
  {
    int u,v,c;cin>>u>>v>>c;
    add(u,v,c),add(v,u,c);
    int pa = find(u),pb = find(v);
    if(pa!=pb) p[pa] = pb;
  }
  for(int i=1;i<=n;i++)
  {
    int pa = find(i);
    if(!id[pa]) id[pa] = ++cnt;
    id[i] = id[pa];
    S[id[i]].push_back(i);
  }
  while(y--)
  {
    int u,v,c;cin>>u>>v>>c;
    add(u,v,c);
    d[id[v]]++;
  }
  queue<int> q;
  for(int i=1;i<=cnt;i++)
    if(!d[i])
      q.push(i);
  while(q.size())
  {
    auto t = q.front();q.pop();
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(auto x:S[t]) pq.push({dist[x],x});
    while(pq.size())
    {
      auto [dis,ver] = pq.top();pq.pop();
      if(st[ver]) continue;
      st[ver] = 1;
      for(int i=h[ver];~i;i=ne[i])
      {
        int j = e[i];
        if(dist[j]>dist[ver] + w[i])
        {
          dist[j] = dist[ver] + w[i];
          if(id[ver]==id[j]) pq.push({dist[j],j});
        }
        if(id[ver]!=id[j]&&--d[id[j]]==0) q.push(id[j]);
      }
    }
  }
  for(int i=1;i<=n;i++)
    if(dist[i]>inf/2) cout<<"NO PATH\n";
    else cout<<dist[i]<<'\n';
  return 0;
}