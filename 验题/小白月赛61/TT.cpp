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
#define Rep(i, a, b) for (int i(a); i < b; ++i)
#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}

// mt19937 rnd(random_device{}());
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x; }

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

class Solution {
 public:
  bool splitArraySameAverage(vector<int> &nums) {
    int n = nums.size(); if (n == 1) return false;
    int m1 = n / 2, m2 = n - m1;

    vector<int> a, b;

    for (int i = 0; i < m1; i++) {
      a.push_back(nums[i]);
    }

    for (int i = m1; i < n; i++) {
      b.push_back(nums[i]);
    }

    int s1 = accumulate(a.begin(), a.end(), 0);
    int s2 = accumulate(b.begin(), b.end(), 0);
    int s = accumulate(nums.begin(), nums.end(), 0);
    
    vector<vector<int> > st(m1 + 1, vector<int>(s1 + 1));

    for (int i = 0; i < 1 << m1; i++) {
      int ct = 0;
      int sum = 0;
      for (int j = 0; j < m1; j++)
        if (i >> j & 1) {
          ++ct;
          sum += a[j];
        }
      st[ct][sum] = 1;
      if (ct && (s * ct) % n == 0 && s * ct / n == sum) {
        return true;
      }
    }

    for (int i = 1; i < 1 << m2; i++) {
      int ct = 0;
      int sum = 0;
      for (int j = 0; j < m2; j++)
        if (i >> j & 1) {
          ++ct;
          sum += b[j];
        }

      if ((s * ct) % n == 0 && s * ct / n == sum) {
        return true;
      }

      for (int j = 1; j <= ((ct == m2) ? m1 - 1 : m1); j++) {
        int now = ct + j;
        int aid = s * now / n - sum;
        if ((s * now) % n == 0) {
          if (aid <= s1 && st[j][aid]) {
            return true;
          }
        }
      }
    }
    return false;
  }
};

void solve() {
  Solution sol; vector<int> a{17,3,7,12,1};
  cout << sol.splitArraySameAverage(a);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  // cin >> T;
  while (T--) solve();
  return 0;
}