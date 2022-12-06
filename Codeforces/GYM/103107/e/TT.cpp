#include <bitsdc++.h>
using namespace std;
const int N = 1000010;
class SA
{
    vector<int> rk, sa, cnt, height, oldrk, px, id;
    int n;
    bool cmp(int x, int y, int w)
    {
        return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
    }

public:
    SA() = default;
    SA(string s)
    {
        int n = s.length(), m = 300;
        this->n = n;
        oldrk.resize(max(m + 1, 2 * n + 1));
        sa.resize(max(m + 1, n + 1));
        rk.resize(max(m + 1, n + 1));
        cnt.resize(max(m + 1, n + 1));
        height.resize(max(m + 1, n + 1));
        px.resize(max(m + 1, n + 1));
        id.resize(max(m + 1, n + 1));
        s = " " + s;
        for (int i = 1; i <= n; ++i)
            ++cnt[rk[i] = s[i]];
        for (int i = 1; i <= m; ++i)
            cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; --i)
            sa[cnt[rk[i]]--] = i;
        for (int w = 1, p;; w <<= 1, m = p)
        {
            p = 0;
            for (int i = n; i > n - w; --i)
                id[++p] = i;
            for (int i = 1; i <= n; ++i)
                if (sa[i] > w)
                    id[++p] = sa[i] - w;
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 1; i <= n; ++i)
                ++cnt[px[i] = rk[id[i]]];
            for (int i = 1; i <= m; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; --i)
                sa[cnt[px[i]]--] = id[i];
            copy(rk.begin(), rk.end(), oldrk.begin());
            p = 0;
            for (int i = 1; i <= n; ++i)
                rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
            if (p == n)
            {
                for (int i = 1; i <= n; ++i)
                    sa[rk[i]] = i;
                break;
            }
        }
        for (int i = 1, k = 0; i <= n; ++i)
        {
            if (rk[i] == 0)
                continue;
            if (k)
                --k;
            while (s[i + k] == s[sa[rk[i] - 1] + k])
                ++k;
            height[rk[i]] = k;
        }
    }
    long long solve()
    {
        long long ans = (long long)n * (n + 1) / 2;
        for (int i = 1; i <= n; i++)
            ans -= height[rk[i]];
        return ans;
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while(t--)
    {
        string s;
        cin >> s;
        SA t(s);
        cout << t.solve();
    }
    return 0;
}
