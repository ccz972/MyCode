

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct Node
{
    int l, r;
    int sum1, sum2, cov1, cov2;
} tr[N << 2];

int h[N], ne[N], e[N], idx;
int fa[N], son[N], dep[N], sz[N];
int dfn[N], top[N], ts;
int A[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int pa)
{
    sz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == pa)
            continue;
        fa[j] = u, dep[j] = dep[u] + 1;
        dfs1(j, u);
        sz[u] += sz[j];
        if (sz[j] > sz[son[u]])
            son[u] = j;
    }
}

void dfs2(int u, int tp)
{
    top[u] = tp, dfn[u] = ++ts;
    if (!son[u])
        return;
    dfs2(son[u], tp);
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == son[u] || j == fa[u])
            continue;
        dfs2(j, j);
    }
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0, -1, -1};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void change1(Node &u, int k)
{
    u.sum1 = k * (u.r - u.l + 1);
    u.cov1 = k;
}

void change2(Node &u, int k)
{
    u.sum2 = k * (u.r - u.l + 1);
    u.cov2 = k;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.cov1 != -1)
    {
        change1(left, root.cov1);
        change1(right, root.cov1);
        root.cov1 = -1;
    }
    if (root.cov2 != -1)
    {
        change2(left, root.cov2);
        change2(right, root.cov2);
        root.cov2 = -1;
    }
}

void pushup(int u)
{
    tr[u].sum1 = tr[u << 1].sum1 + tr[u << 1 | 1].sum1;
    tr[u].sum2 = tr[u << 1].sum2 + tr[u << 1 | 1].sum2;
}

void modify1(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r)
    {
        tr[u].sum1 = tr[u].r - tr[u].l + 1;
        tr[u].cov1 = 1;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid)
        modify1(u << 1, l, r);
    if (r > mid)
        modify1(u << 1 | 1, l, r);
    pushup(u);
}

void modify2(int u, int l, int r)
{
    // cout<<tr[u].l<<" "<<tr[u].r<<" "<<l<<" "<<r<<endl;
    if (!tr[u].sum1)
        return;
    if (l <= tr[u].l && tr[u].r <= r && tr[u].r - tr[u].l + 1 == tr[u].sum1)
    {
        tr[u].sum2 = tr[u].sum1;
        tr[u].cov2 = 1;
        return;
    }
    if (tr[u].l == tr[u].r)
        return;
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid)
        modify2(u << 1, l, r);
    if (r > mid)
        modify2(u << 1 | 1, l, r);
    pushup(u);
}

void modify3(int u, int l, int r)
{
    if (l <= tr[u].l && tr[u].r <= r)
    {
        tr[u].sum1 = tr[u].sum2 = 0;
        tr[u].cov1 = tr[u].cov2 = 0;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid)
        modify3(u << 1, l, r);
    if (r > mid)
        modify3(u << 1 | 1, l, r);
    pushup(u);
}

int query(int u, int l, int r)
{
    // cout<<tr[u].l<<" "<<tr[u].r<<endl;
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].sum2;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid)
        res += query(u << 1, l, r);
    if (r > mid)
        res += query(u << 1 | 1, l, r);
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    build(1, 1, N - 1);
    while (T--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            h[i] = -1;
        ts = idx = 0;
        for (int i = 2; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            add(x, i);
        }
        dfs1(1, -1);
        dfs2(1, 1);
        while (q--)
        {
            int sz1, sz2, sz3;
            scanf("%d%d%d", &sz1, &sz2, &sz3);
            // cout<<sz1<<" "<<sz2<<" "<<sz3<<endl;
            for (int i = 1; i <= sz1; i++)
            {
                int x;
                scanf("%d", &x);
                A[i] = x;
                while (top[x] != 1)
                {
                    modify1(1, dfn[top[x]], dfn[x]);
                    x = fa[top[x]];
                }
                modify1(1, dfn[1], dfn[x]);
            }
            for (int i = 1; i <= sz2; i++)
            {
                int x;
                scanf("%d", &x);
                while (top[x] != 1)
                {
                    modify2(1, dfn[top[x]], dfn[x]);
                    x = fa[top[x]];
                    // cout<<x<<endl;
                }
                modify2(1, dfn[1], dfn[x]);
            }
            int ans = 0;
            for (int i = 1; i <= sz3; i++)
            {
                int x;
                scanf("%d", &x);
                // cout<<x<<endl;
                ans += query(1, dfn[x], dfn[x] + sz[x] - 1);
                modify3(1, dfn[x], dfn[x] + sz[x] - 1);
            }
            for (int i = 1; i <= sz1; i++)
            {
                int x = A[i];
                while (top[x] != 1)
                {
                    modify3(1, dfn[top[x]], dfn[x]);
                    x = fa[top[x]];
                }
                modify3(1, dfn[1], dfn[x]);
            }
            printf("%d\n", ans);
        }
    }
    
    return 0;
}