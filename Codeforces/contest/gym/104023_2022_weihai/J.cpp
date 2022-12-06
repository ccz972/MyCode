#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> cnt;
  vector<int> a(n); for (int &x: a) cin >> x, cnt[x] ++;
  sort(a.begin(), a.end());

  vector<pair<int, int > > b(k);

  for (auto &[x ,y]: b) {
    cin >> x >> y;
    if (cnt[x] > y) return cout << "FuuFuu\n", void();
  }


  sort(b.begin(), b.end());
  // vector<pair<int, int> > c;
  // vector<vector<pair<int, int > > > limit;
  // if (true) {
  //   int i = 0;
  //   while (i < n && a[i].limit)
  // }
  
  

  // if (b[0].first != 0) {
  //   c.push_back({0, n});
  // }

  // for (int i = 0; i < k; i ++ ) {
  //   if (b[i].second == 0) {
  //     c.push_back(b[i]);
  //     if (i != k - 1) {
  //       if (b[i + 1].first != b[])
  //     }
  //   }
  // }

  ll ret = 0;
  int left = 0;  
  for (int i = 0; i < k; i ++ ) {
    int j = i;
    while (j + 1 < n && b[j + 1].second != 0) {
      ++ j;
    }

    int low = b[i].first, high = b[j].first;
    ll sum = a[left];
    auto nleft = left;
    while (left + 1 < n && a[left + 1] < high) {
      ++ left;
      sum += a[left];
    }

    ll cnt = left - nleft + 1;

    for (int k = i; k < j; k ++ ) {
      if (cnt <= b[k].second) {
        sum -= cnt * b[k].first;
        break;
      }
      sum -= 1ll * b[k].first * b[k].second;
    }

    ret += sum;

    // for (int k = i; k < j; k ++ ) {

    // }

    i = j;
  }

  cout << ret << "\n";
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
