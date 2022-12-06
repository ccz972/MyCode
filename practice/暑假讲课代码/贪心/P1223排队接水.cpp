// @url https://www.luogu.com.cn/problem/P1223

#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

const int N = 1010;

int a[N], id[N];

bool cmp(int x, int y) {
  return a[x] < a[y];
}

int main() {
  
  int n; cin >> n;

  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    id[i] = i;
  }

  sort(id + 1, id + 1 + n, cmp);

  for(int i = 1; i <= n; i ++ ) {
    cout << id[i] << " ";
  }
  
  cout << "\n";

  double sum = 0;

  for(int i = 1; i <= n; i ++ ) {
    sum += a[id[i]] * (n - i);
  }

  cout << fixed << setprecision(2) << sum / n << "\n";

  return 0;
}