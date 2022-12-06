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

void init() {
  rep(i, 1, n) maxid[0][i] = minid[0][i] = i;
  for (int j = 1; j < M; j ++ ) {
    for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) {
      maxid[j][i] = A[maxid[j - 1][i]] >= A[maxid[j - 1][i + (1 << (j - 1))]] 
                    ? maxid[j - 1][i] : maxid[j - 1][i + (1 << (j - 1))];
      minid[j][i] = A[minid[j - 1][i]] <= A[minid[j - 1][i + (1 << (j - 1))]] 
                    ? minid[j - 1][i] : minid[j - 1][i + (1 << (j - 1))];
    }
  } 
}

int getmax_id(int l, int r) {
  int k = __lg(r - l + 1) + 1;
  int left = maxid[k - 1][l];
  //4 5
  int right = maxid[k - 1][r - (1 << (k - 1)) + 1];
  assert(l + (1 << k - 1) - 1 <= r);
  assert(r - (1 << k - 1) + 1 >= l);
  if (A[left] >= A[right]) return left; //{ cout << "maxid > " << l << " " << r << " " << k << " " << k << " " << left << endl; return left;}
  // cout << "maxid > " << l << " " << r << " " << k << " " << k << " " << right << endl;
  return right;
}

int getmin_id(int l, int r) {
  int k = __lg(r - l + 1) + 1;
  int left = minid[k - 1][l];
  //4 5
  int right = minid[k - 1][r - (1 << (k - 1)) + 1];
  assert(l + (1 << k - 1) - 1 <= r);
  assert(r - (1 << k - 1) + 1 >= l);
  if (A[left] <= A[right]) return left; ///{ cout << "minid > " << l << " " << r << " " << left << endl; return left;}
  // cout << "minid > " << l << " " << r << " " << right << endl;
  return right;
}



void solve() {
  cin >> n;
  vector<int> a(n); for (int &x: a) cin >> x;
  auto b = a; sort(all(b));
  b.erase(unique(all(b)), b.end());

  auto find = [&] (int x) {
    return lower_bound(all(b), x) - b.begin() + 1;
  };

  

  for (int &x: a) {
    x = find(x);
    A[++ m] = x;
    //cout << x << " ";
  }
  
  //cout << endl;


  init();

  
  
  int start = getmax_id(1, n), R = n; 
  int ans = 1;
  while (true) {
    if (start <= 1) {
      break;
    }
    // cout << start << " " << R << endl;
    int small = A[getmin_id(start, R)];
    int great = A[getmax_id(1, start - 1)];
    // cout << "small = " << small << " " << great << endl;
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