// https://codeforces.com/contest/1718/submission/168582202
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout <<#x << ": " << x << "\n";
constexpr int N = 2E5 + 10;

int n, q;
int a[N];
vector<int> divisors;
vector<long long> sum[N];
priority_queue<long long> heap, del;

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];
  for (int i = n - 1; i >= 1; i -- ) if (not (n % i)) {
    bool ok = true;
    for (auto &d : divisors) if (not (d % i)) {
      ok = false;
      break;
    }
    if (!ok) continue;
    divisors.emplace_back(i);
    sum[i].resize(i);
  }

  for (auto& d: divisors) { //步长为 d 并且 起点 (idx mod i) = j 的值
    for (int i = 1; i <= n; i ++ ) sum[d][i % d] += (long long)a[i] * d; 
    for (int i = 0; i <= d - 1; i ++ ) heap.push(sum[d][i]);
  }

  cout << heap.top() << "\n";

  while (q -- ) {
    long long p, x; 
    cin >> p >> x;

    long long diff = x - a[p];  
    a[p] = x;

    for (auto& d: divisors) {
      del.push(sum[d][p % d]);
      sum[d][p % d] += diff * d;
      heap.push(sum[d][p % d]);
    }

    while (!del.empty() && heap.top() == del.top()) {
      heap.pop(); del.pop();
    }

    cout << heap.top() << "\n";
  }

  for (auto &d: divisors) sum[d].clear();
  divisors.clear();
  while (!heap.empty()) heap.pop();
  while (!del.empty()) del.pop();
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T -- ) {
    solve();
  }
  return 0;
}