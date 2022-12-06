#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m;

struct node {
  int cnt, sum;
    // sum / cnt < T.sum / T.cnt
  bool operator < (const node &T) const {
    if(sum * T.cnt != T.sum * cnt)
      return sum * T.cnt < T.sum * cnt;

    return cnt < T.cnt;
  }

} a[N];



void solve() {

  double ans = 0;
  int now = 0;

  for(int i = 0; i < n; i ++ ) {
    cin >> a[now].cnt >> a[now].sum;

    if(a[now].cnt == 0) {
      continue;
    } else if(a[now].sum == 0) {
      ans += a[now].cnt;
    } else {
      now ++;
    }

  }

  sort(a, a + now);

  for(int i = 0; i < now; i ++ ) {
    if(m >= a[i].sum) {
      ans += a[i].cnt;
      m -= a[i].sum;    
    } else {
      ans += 1.0 * m * a[i].cnt / a[i].sum;
      break;
    }
  }
  //保留三位有效数字  111.1111
//   cout << fixed << setprecision(3) << ans + 0.0005 << "\n"; //不能用

  printf("%.3lf\n", ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  while(cin >> m >> n, n != -1 || m != -1)
    solve();
  return 0;
}