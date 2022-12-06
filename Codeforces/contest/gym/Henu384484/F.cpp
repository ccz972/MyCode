#include <bits/stdc++.h>
using namespace std;

double calc(int n) {
  return 10.0 * sin(2.0 / n) * cos(10 * n) / sqrt(n);
}
constexpr int N = 1e5 + 10;

double s[N];

void solve() {
  int n; cin >> n;
  if(n >= N) {
    cout << s[N - 1] << "\n";
  } else {
    cout << s[n] << "\n";
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  for(int i = 1; i < N; i ++ ) {
    s[i] = s[i - 1] + calc(i);
  }
  int T; cin >> T;
  while(T -- )
    solve();
  return 0;
}