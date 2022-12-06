#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E6 + 10;
bool st[N];
int cnt, primes[N], phi[N];
void get() {
  for (int i = 2; i < N; i++) {
    if (!st[i]) primes[cnt++] = i, phi[i] = i - 1; 
    for (int j = 0; primes[j] * i < N; j ++ ) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        phi[primes[j] * i] = phi[i] * primes[j];
        break;
      } else {
        phi[primes[j] * i] = phi[i] * (primes[j] - 1);
      }
    }
  }
}

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  } else {
    int d = exgcd(b, a % b, y , x);
    y -= a / b * x;
    return d;
  }
}

void solve() {
  get();
  for (int i = 1; i <= 10; i ++ ) {
    cout << phi[i] << " \n"[i == 10];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while (T -- ) {
    solve();
  }
  return 0;
}