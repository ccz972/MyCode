#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, k; 
double a[N];

bool check(double x) {
  if(!x) return true;
  int cnt = 0;
  for(int i = 0; i < n; i ++ ) {
    cnt += floor(a[i] / x);
  }
  return cnt >= k;
}

void solve1() {
  
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i ++ ) {
    scanf("%lf", &a[i]);
  }

  double l = 0, r = 10000;

  while(fabs(r - l) > 1e-5) {
    double mid = (l + r) / 2;
    if(check(mid)) l = mid;
    else r = mid;
  }
  //2.005  2.0049999
  printf("%.2lf\n", l + 0.0001);
}

void solve2() {
  
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i ++ ) {
    scanf("%lf", &a[i]);
  }

  // double l = 0, r = 10000;
  double l = 0, r = 10000;
  //
  //  eps = 1e-8

  for(int i = 0; i < 100; i ++ ) {
    double mid = (l + r) / 2;
    if(check(mid)) l = mid;
    else r = mid;
  }

  // }
  //0.1  
  //2.121321545646489648
  //2.005  --> 2.0049999999
  //2.01
  // cout << fixed << setprecision(2) << (l + 0.0001) << "\n";
  printf("%.2lf\n", l + 0.0001);
}




int main() {
  
  // freopen("debug.txt", "w", stdout);
  // solve1();
  solve2();
  // printf("%.2lf", 2.466);
  return 0;
}