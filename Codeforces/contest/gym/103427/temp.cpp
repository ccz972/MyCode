#include <iostream>
#include <algorithm>

using namespace std;

int n, a[200010];

int main() {
  n = 0;
  int x;
  while (cin >> x) {
    if (!x) break;
    a[++ n] = x;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i ++ ) cout << a[i] << " ";
  return 0;
}
