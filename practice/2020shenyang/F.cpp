#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define PII pair<int, int>
#define debug(x) cout << #x << " > " << x << "\n"
#define all(a) a.begin(), a.end()

mt19937 rng(random_device{}());
int rnd(int x) {
  return rng() % x;
}
constexpr int N = 1E6 + 10;
constexpr int M = 21;
int A[N];
int n, m;
int maxid[M][N], minid[M][N];
int lg[N];
void init() {
  lg[1] = 0;
  for (int i= 2; i <= n; i ++ ) lg[i] = lg[i >> 1] + 1;
  rep(i, 1, n) maxid[0][i] = minid[0][i] = i;
  for (int j = 1; j < M; j ++ ) {
    for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) {
      maxid[j][i] = A[maxid[j - 1][i]] > A[maxid[j - 1][i + (1 << (j - 1))]] 
                    ? maxid[j - 1][i] : maxid[j - 1][i + (1 << (j - 1))];
      minid[j][i] = A[minid[j - 1][i]] <= A[minid[j - 1][i + (1 << (j - 1))]] 
                    ? minid[j - 1][i] : minid[j - 1][i + (1 << (j - 1))];
    }
  } 
}

int getmax_id(int l, int r) {
  int k = lg[r - l + 1]; 
  int left = maxid[k][l];
  int right = maxid[k][r - (1 << k) + 1];
  assert(l + (1 << k) - 1 <= r);
  assert(r - (1 << k) + 1 >= l);
  if (A[left] > A[right]) return left; 
  return right;
}

int getmin_id(int l, int r) {
  int k = lg[r - l + 1];
  int left = minid[k][l];
  int right = minid[k][r - (1 << k) + 1];
  assert(l + (1 << k) - 1 <= r);
  assert(r - (1 << k) + 1 >= l);
  
  if (A[left] <= A[right]) return left; 
  return right;
}



void solve() {
  cin >> n;
  rep(i, 1, n) cin >> A[i];

  init();
  
  int start = getmax_id(1, n), R = n; 

  int ans = 1;

  while (true) {
    if (start <= 1) {
      break;
    }
    int small = A[getmin_id(start, R)];
    int great = A[getmax_id(1, start - 1)];
    if (great > small) {
      start = getmax_id(1, start - 1);
    } else {
      ++ ans;
      R = start - 1;
      start = getmax_id(1, R);
    }
  }

  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}