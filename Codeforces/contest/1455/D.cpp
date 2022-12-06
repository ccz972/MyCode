#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    if (is_sorted(a.begin(), a.end())) {
      cout << "0\n";
      continue;
    }
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n - 1 && !flag; i ++ ) {
      if (a[i] > a[i + 1]) {
        if(a[i] >= k) {
          int j = i;

          while(j - 1 >= 0 && a[j - 1] > k) {
            -- j;
            if(a[j] == a[j + 1]) {
              flag = true;
            }
          }

          int tmp = a[i];
          
          for (int p = i - 1; p >= j; p -- ) {
            a[p + 1] = a[p];
          }

          a[j] = k;
          k = tmp;
          if(a[i] > a[i + 1]) {
            flag = true;
          }
          cnt += i - j + 1;

        } else {
          if(k < a[i + 1])

        }
        
      }
    }

    if (!flag && is_sorted(a.begin(), a.end())) {
      cout << cnt << "\n";
    } else {
      cout << "-1\n";
    }




    // cout << "-1\n";
  }
}