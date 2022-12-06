#include <bits/stdc++.h>
#include <Debugger>

using namespace std;



class Solution {
public:
    using ll = long long;
    #define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
    #define dec(i, a, b) for (int i(b); i >= a; -- i ) 
    template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
    template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

    long long makeSimilar(vector<int>& nums, vector<int>& target) {
      vector<int> a, b; int n = nums.size();
      for (int i = 0; i < n; i ++ ) if (nums[i] & 1) {
        a.emplace_back(nums[i]);
      }

      for (int i = 0; i < n; i ++ ) if (target[i] & 1) {
        b.emplace_back(target[i]);
      }

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());


      ll sum = 0, add = 0, del = 0;

      int m = a.size();

      for (int i = 0; i < m; i ++ ) {
        if (a[i] < b[i]) {
          ll aim = b[i] - a[i];
          if (add >= aim) {
            add -= aim;
          } else {
            aim -= add;
            add = 0;
            del += aim;
            sum += aim;
          }
        } else {
          ll aim = abs(b[i] - a[i]);
          if (del >= aim) {
            del -= aim;
          } else {
            aim -= del;
            del = 0;
            add += aim;
            sum += aim;
          }
        }
      }

      a.clear(), b.clear();

      for (int i = 0; i < n; i ++ ) if (~nums[i] & 1) {
        a.emplace_back(nums[i]);
      }

      for (int i = 0; i < n; i ++ ) if (~target[i] & 1) {
        b.emplace_back(target[i]);
      }

      sort(a.begin(), a.end());
      sort(b.begin(), b.end());

      m = a.size();

      for (int i = 0; i < m; i ++ ) {
        if (a[i] < b[i]) {
          ll aim = b[i] - a[i];
          if (add >= aim) {
            add -= aim;
          } else {
            aim -= add;
            add = 0;
            del += aim;
            sum += aim;
          }
        } else {
          ll aim = abs(b[i] - a[i]);
          if (del >= aim) {
            del -= aim;
          } else {
            aim -= del;
            del = 0;
            add += aim;
            sum += aim;
          }
        }
      }

      return sum / 2;

    }
};

void solve() {
  Solution s;
  // vector<int> a{8,12,6}, b{2,14,10};

  vector<int> a{1,2,5}, b{4,1,3};

  cout << s.makeSimilar(a, b);


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
