#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#define mod 10000007
#define inf 0x3f3f3f3f
#define N 2010
#define M 131
#define ll long long
#define pii pair<int,int>
#define db double
using namespace std;

int n,m,s,t;
int h[N],l[N],w[N],e[N],ne[N],idx;
int dist[N],cost[N];
int st[N];
 
void init()
{
//	memset(dist,0x3f,sizeof dist);
//	memset(cost,0x3f,sizeof cost);
//	memset(st,false,sizeof st);
	for(int i = 1; i <= n; i ++ )
	{
		dist[i] = inf;
		cost[i] = inf;
		st[i] = 0;
    h[i] = -1;
	}
	dist[s] = 0;
	cost[s] = 0;
}

void add(int a,int b,int c,int d) 
{
	e[idx] = b;
	l[idx] = c;
	w[idx] = d;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}

void dijkstra()
{
	init();
	
	priority_queue<pii,vector<pii>, greater<pii> > heap;//距离 点号 
	heap.push({0,s});
	
	while(heap.size())
	{
		pii tmp = heap.top();
		heap.pop();
		int t = tmp.second,dis = tmp.first;
		if(!st[t]) st[t] = true;
		else continue;
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			// if(st[j]) continue;
			if(dist[j] > dis + l[i])
			{
				dist[j] = dis + l[i];
				cost[j] = cost[t] + w[i];
				heap.push({dist[j],j});
			} else if(dist[j] == dis + l[i])
			{
				// cost[j] = min(cost[t] + w[i],cost[j]);
        if(cost[j] > cost[t] + w[i]) {
          cost[j] = cost[t] + w[i];
          heap.push({dist[j],j});
        }
			}
		}
	}
	printf("%d %d\n",dist[t],cost[t]);
}

int main()
{
	while(scanf("%d%d",&n,&m),n + m)
	{
		//memset(h,-1,sizeof h);
		idx = 0;
		
		for(int i = 1; i <= m; i ++ )
		{
			int a,b,c,e;
			scanf("%d%d%d%d",&a,&b,&c,&e);
			add(a,b,c,e);
			add(b,a,c,e);
		}
		
		scanf("%d%d",&s,&t); 
		
		dijkstra();
	}

	return 0;
}