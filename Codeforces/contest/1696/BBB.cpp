#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], Tmax, Tmin;
int main(){
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> Tmin >> Tmax;
    Tmax -= Tmin;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= Tmin;
    vector<pair<int, int> > que;
    for (int i = n; i >= 1; i--) que.push_back(make_pair(a[i], 1));
    long long times = 0;
    int p = 0;
    while (m--) {
        int t, k;
        cin >> t >> k;
        times += t;
        long long sum = 1LL * Tmin * k;
        if (k > n) sum += 1LL * Tmax * (k - n), k = n;
        que.push_back(make_pair((Tmax + times) % (Tmax + 1), k));
        while (p < que.size() && que[p].second <= k) {
            int temp = (que[p].first - times) % (Tmax + 1);
            if (temp < 0) temp += Tmax + 1;
            sum += 1LL * que[p].second * temp;
            k -= que[p].second;
            p++;
        }
        if (p < que.size() && k > 0) {
            int temp = (que[p].first - times) % (Tmax + 1);
            if (temp < 0) temp += Tmax + 1;
            sum += 1LL * k * temp;
            que[p].second -= k;
            k = 0;
        }
        cout << sum << '\n';
    }
}