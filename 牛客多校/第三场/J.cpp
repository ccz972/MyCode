#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
typedef pair<int,int> PII;
// map<PII,bool> st;
set<PII> st;
map<PII,int> dist;
int dir[N][5];
PII S,T;
int n;

struct Node {
    int x, y, t;
};

bool bfs()
{
    deque<Node> q;
    Node res = {S.first,S.second};
    for(int i = 1; i <= 4; i ++) {
		if(S.first == dir[S.second][i]) {
			res.t = i;
            break;
		}	
	}
        
    q.push_back(res);
    dist[S] = 0;
    while(q.size()) {
        auto t = q.front();
        q.pop_front();
        if(T.first == t.x && T.second == t.y) return 1;
        if(st.count({t.x,t.y})) continue;
        // st[{t.x,t.y}] = 1;
		st.insert({t.x, t.y});
        int tmp = dir[t.y][t.t % 4 + 1];
        for(int i=1;i<=4;i++) {
            int j = dir[t.y][i], w = 1;
            if(!j) continue;
            if(j == tmp) w = 0;
            PII res = {t.y, j};
            int idx;
            for(int k=1;k<=4;k++) if(t.y==dir[j][k]) {
				idx = k;
				break;
			}
            if(!dist.count(res)|| dist[res] > dist[{t.x,t.y}] + w)  {
                dist[res] = dist[{t.x,t.y}] + w;
                if(w) q.push_back({res.first,res.second,idx});
                else q.push_front({res.first,res.second,idx});
            }
        }
    }
    return 0;
}

int main()
{
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=4;j++)
            scanf("%d",&dir[i][j]);
    scanf("%d %d %d %d",&S.first,&S.second,&T.first,&T.second);
    if(!bfs()) printf("-1\n");
    else printf("%d\n",dist[T]);
    return 0;
}