#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10;
typedef pair<int, int> PII;

int n, m;                         // 点的数量
int h[N], w[N], e[N], ne[N], idx; // 邻接表存储所有边
int dist[N];                      // 存储所有点到1号点的距离
bool st[N];                       // 存储每个点的最短距离是否已确定

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push(make_pair(0, 1)); // first存储距离，second存储节点编号
    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push(make_pair(dist[j], j));
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin >> m >> n;
    memset(h, -1, sizeof h);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}
