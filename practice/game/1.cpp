#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;
class Solution {
public:
  bool splitArraySameAverage(vector<int>& nums) {
    int n = SZ(nums); if (n == 1) return false;
    int m1 = n / 2, m2 = n - m1;
    vector<int> a, b;
    Rep(i, 0, m1) a.eb(nums[i]);
    Rep(i, m1, n) b.eb(nums[i]);
    int s = accumulate(all(nums), 0);
    int s1 = accumulate(all(a), 0);
    vector<vector<int> > f(m1 + 1, vector<int> (s1 + 1));

    auto chk = [&] (int x, int y) {
      //x / y = s / n
      if ((s * y) % n) return false;
      return s * y / n == x;
    };

    for (int i = 0; i < 1 << m1; i ++ ) {
      int sum = 0, cnt = 0;
      for (int j = 0; j < m1; j ++ ) if (i >> j & 1) {
        sum += a[j];
        cnt ++;
      }
      if (cnt && chk(sum, cnt)) {
        return true;
      }
      f[cnt][sum] = 1;
    }

    for (int i = 1; i < 1 << m2; i ++ ) {
      int sum = 0, cnt = 0;
      for (int j = 0; j < m2; j ++ ) if (i >> j & 1) {
        sum += b[j]; cnt ++;
      }
      if (chk(sum, cnt)) {
        return true;
      }
      for (int j = 1; j <= m1; j ++ ) {
        //s / n = (sum + x) / (j + cnt)
        int p = s * (j + cnt); if (p % n == 0) {
          int q = p / n;
          if (q >= sum && q - sum <= s1) {
            if (f[j][q - sum]) return true;
          }
        }
      }
    }
    return false;
  }
};
void solve() {
  Solution sol;
  vector<int> a{1, 2};
  sol.splitArraySameAverage(a);
  
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}