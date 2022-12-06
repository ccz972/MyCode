#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll a[N];

void solve() {

  int n; scanf("%d", &n);
  
  for(int i = 0; i < n; i ++ ) scanf("%lld", &a[i]);

  sort(a, a + n);


  int q; scanf("%d", &q);

  while(q -- ) {
    ll x; scanf("%lld", &x);

    if(x < a[0]) {
      puts("0");
      continue;
    }

    int l = 0, r = n - 1;

    //a[i] <= x  最右边的点

    while(l < r) {
      int mid = (l + r + 1) / 2;
      if(a[mid] <= x) l = mid;
      else r = mid - 1;
      // printf("%d %lld %lld\n", l, a[mid], x);
    }

    printf("%d\n", l + 1);

  }

}

int main() {
  solve();
  return 0;
}