#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
// typedef pari<int,PII> PIII;
const int N = 17;

bool st[N][N],g[N*N + N][N*N + N];
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
int n,m,K,xs,ys,xt,yt;

struct Node
{
    int x1,y1,x2,y2;
}wall[N];

bool bfs()
{
    queue<PII> q;
    memset(st,0,sizeof st);
    st[xs][ys] = 1;
    q.push({xs,ys});
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        if(t.first==xt&&t.second==yt) return 1;
        for(int i=0;i<4;i++)
        {
            int nx = t.first + dx[i],ny = t.second + dy[i];
            int w = 0;
            if(nx>n||nx<=0||ny>m||ny<=0) continue;
            if(st[nx][ny]) continue;
            int tx,ty;
            if(!dx[i]) tx = 4*nx - 1,ty = min(t.second,ny);
            else tx = min(t.first,nx)*4,ty = ny;
            if(g[tx][ty]) continue;
            st[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&K);
        scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
        xs++,ys++,xt++,yt++;
        memset(g,0,sizeof g);
        for(int i=1;i<=K;i++)
        {
            int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            wall[i] = {x1,y1,x2,y2};
        }
        int ans = INT_MAX;
        for(int i=0;i<1<<K;i++)
        {
            memset(g,0,sizeof g);
            int cnt = 0;
            for(int j=0;j<K;j++)
                if(i>>j&1)
                {
                    cnt++;
                    int x1 = wall[j+1].x1,x2 = wall[j+1].x2,y1 = wall[j+1].y1,y2 = wall[j+1].y2;
                    if(x1==x2){
                        if(y1>=y2) swap(y1,y2);
                        for(int i=y1+1;i<=y2;i++)
                            g[4*x1][i] = 1;
                    }
                    else{
                        if(x1>=x2) swap(x1,x2);
                        for(int i=x1;i<=x2-1;i++)
                            g[4*i+1][y1] = 1;
                    }
                }
            if(bfs()) ans = min(K-cnt,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}