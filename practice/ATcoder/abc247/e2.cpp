#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
 public:
  long long countSubarrays(vector<int> &nums, int min_k, int max_k) {
    long long ans = 0L;
    int n = nums.size(), min_i = -1, max_i = -1, i0 = -1;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (x == min_k) min_i = i;
      if (x == max_k) max_i = i;
      if (x < min_k || x > max_k) i0 = i;  // 子数组不能包含 nums[i0]
      ans += max(min(min_i, max_i) - i0, 0);
    }
    return ans;
  }
};

void solve() {
  int n; cin >> n;
  int x, y; cin >> x >> y;
  vector<int> a(n); for (int &x: a) cin >> x;
  Solution s;
  cout << s.countSubarrays(a, y, x) << "\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
